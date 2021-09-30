#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            if(max_product<((long long)numbers[first]) * numbers[second])
                max_product = ((long long)numbers[first]) * numbers[second];
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int max_index_1=-1;
    for(int i=0;i<n;i++)
    {
        if(max_index_1==-1 || numbers[i]>numbers[max_index_1])
            max_index_1 = i;
    }

    int max_index_2=-1;
    for(int j=0;j<n;j++)
    {
        if(j!= max_index_1 && (max_index_2==-1 || numbers[j]>numbers[max_index_2]))
            max_index_2 = j;
    }

    std::cout<<max_index_1<<' '<<max_index_2<<"\n";
    max_product = ((long long)numbers[max_index_1])*numbers[max_index_2];
    return max_product;
}

int main() {
    while(true){
        int n = rand() % 10 + 2;
        std::cout<<n<<"\n";
        std::vector<int> a;
        for(int i = 0; i<n; i++){
            a.push_back(rand() % 100000);
        }
        for(int i=0;i<n;i++){
            std::cout<<a[i]<<' ';
        }
        std::cout<<"\n";
        long long res1  =  MaxPairwiseProduct(a);
        long long res2  =  MaxPairwiseProductFast(a);
        if(res1!=res2){
            std::cout<<"Wrong Answer: "<<res1<<' '<<res2<<"\n";
            break;
        }
        else{
            std::cout<<"OK\n";
        }
    }   


    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    return 0;
}
