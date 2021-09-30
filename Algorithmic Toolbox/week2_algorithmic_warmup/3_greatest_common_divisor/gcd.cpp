#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_efficient(long long a, long long b) {
  long long a_p;
  if(b==0)
    return a;
  a_p = a%b;
  return gcd_efficient(b,a_p);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
//  std::cout << gcd_naive(a, b) << std::endl;
  std::cout <<gcd_efficient(a, b) <<std::endl;
  return 0;
}
