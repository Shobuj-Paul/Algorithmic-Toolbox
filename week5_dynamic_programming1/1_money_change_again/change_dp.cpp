#include <iostream>

int get_change(int m) {
  //write your code here
  int coins[] = {1,3,4};
  int MinNumCoins[m+1];
  MinNumCoins[0] = 0;
  int NumCoins = 0;
  for(int i=1;i<m+1;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(i>=coins[j])
      {
        NumCoins = MinNumCoins[i-coins[j]] + 1;
        if(NumCoins<MinNumCoins[i])
          MinNumCoins[i] = NumCoins;
      }
    }
  }  
  return MinNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
