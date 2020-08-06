#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::vector;
using std::pair;
using std::make_pair;
using std::min;

bool valuesPerWeight(const pair<double,double> &a, const pair<double,double> &b) { 
    return(a.second/a.first > b.second/b.first); 
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  vector< pair<double, double> > vw;
  for(int i = 0; i < weights.size(); i++){
    vw.push_back(make_pair(weights[i], values[i]));
  }

  sort(vw.begin(), vw.end(), valuesPerWeight);
  
  for(int i = 0; i < vw.size(); i++){
    if(capacity == 0) return value;
    int a = min((int) vw[i].first, capacity);
    value = value + a*vw[i].second/vw[i].first;
    capacity = capacity - a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
  return 0;
}
