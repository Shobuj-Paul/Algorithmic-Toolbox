#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_efficient(long long a, long long b) {
  long long a_p;
  if(b==0)
    return a;
  a_p = a%b;
  return gcd_efficient(b,a_p);
}

long long lcm_fast(long long a, long long b){
  return (a/gcd_efficient(a,b))*b;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
