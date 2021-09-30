#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0, coins, change_left, deno[] = {10,5,1};
  for(int i = 0;i<3; i++)
  {
    coins = m/deno[i];
    change_left = m%deno[i];
    n+=coins;
    m = change_left;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
