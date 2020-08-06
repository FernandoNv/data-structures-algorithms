#include <iostream>
#include <vector>

int get_change(int m) {
  int coins[3] = {10, 5, 1};
  int sum = 0;
  std::vector<int> change;
  for(int i = 0; i < 3; i++){
    while(sum + coins[i] <= m){
      sum = sum + coins[i];
      change.push_back(coins[i]);
    }
  }
  
  return change.size();
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
