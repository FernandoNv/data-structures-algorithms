#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[right];
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = (right+left)/2;
  int resultLeft = get_majority_element(a, left, mid);
  int resulRight = get_majority_element(a, mid, right);
  int countL = 0;
  int countR = 0;
  for(int i = left; i < right; i++){
    if(a[i] == resultLeft) countL++;
    if(a[i] == resulRight) countR++;
  }
  if(countL > (right-left)/2){
    return resultLeft;
  }else if(countR > (right-left)/2){
    return resulRight;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
