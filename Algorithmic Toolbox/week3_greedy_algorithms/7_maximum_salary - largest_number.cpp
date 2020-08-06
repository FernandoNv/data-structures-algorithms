#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

using std::vector;
using std::string;

bool isGreaterOrEqual(string a, string b){
  if(a.size() > b.size()) return !isGreaterOrEqual(b, a);

  int n = a.size() - 1;
  for(int i = 0; i <= n; i++){
    if(a[i] > b[i]) return true;
    if(a[i] < b[i]) return false;
  }
  for(int i = n+1; i < b.size(); i++){
    if(a[0] > b[i]) return true;
    if(a[0] < b[i]) return false;
  }

  return true;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  while(a.size() > 0) {
    int maxDigit = 0;

    for(int i = 0; i < a.size(); i++){
      if(isGreaterOrEqual(a[i], a[maxDigit]))
        maxDigit = i;
    }
    ret << a[maxDigit];
    a.erase(a.begin() + maxDigit);
  }

  string result;
  ret >> result;
  return result;
}

string naive_largest_number(vector<string> a){
  vector<string> values(a.size());
  for(int i = 0; i < a.size(); i++){
    std::stringstream ret;
    ret << a[i];
    for(int j = 0; j < a.size(); j++){
      if(i != j)
        ret << a[j];
    }
    string result;
    ret >> result;
    values.push_back(result);
  }

  return *std::max_element(values.begin(), values.end());
}

void runStressTest(){
  srand(time(NULL));
  while(true){
    int n = rand() % 10 + 1;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
      a[i] = std::to_string(rand() % 1000 + 1);
    }

    std::cout << n << "\n";
    for(int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout<<"\n";

    string fast = largest_number(a);
    string naive = naive_largest_number(a);

    std::cout << fast << " ";
    std::cout << naive << "\n";
    if(fast != naive) break;
  }

}

int main() {
  runStressTest();


  // int n;
  // std::cin >> n;
  // vector<string> a(n);
  // for (size_t i = 0; i < a.size(); i++) {
  //   std::cin >> a[i];
  // }
  // std::cout << naive_largest_number(a);
}
