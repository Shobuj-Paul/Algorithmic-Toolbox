#include <iostream>
#include <vector>

using std::vector;
using std::min;

double get_max_ratio(vector<int> weights, vector<int> values)
{
  int n = values.size(), index;
  double max = 0;
  for(int i=0;i<n;i++)
  {
    if(weights[i]!=0 && max < (double) values[i]/weights[i])
    {
      max = (double) values[i]/weights[i];
      index = i;
    }
  }
  return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0, a;

  // write your code here
  int n = values.size();
  for(int i=0;i<n;i++)
  {
    if(capacity==0)
      return value;
    int max_index = get_max_ratio(weights, values);
    a = min(weights[max_index],capacity);
    value = value + a * (double) values[max_index]/weights[max_index];
    weights[max_index] = weights[max_index] - a;
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

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
