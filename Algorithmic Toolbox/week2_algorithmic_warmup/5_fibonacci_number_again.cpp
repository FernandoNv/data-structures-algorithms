#include <iostream>
#include <vector>

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    std::vector<long long> list;
    list.push_back(0);
    list.push_back(1);
    long long a = 0;
    long long b = 1;
    long long c = 0;
    for(int i = 0; i < n; i++){
        c = (a + b) % m;
        if(b == 0 && c == 1){
            list.pop_back();
            break;
        }
        list.push_back(c);
        a = b;
        b = c;
    }
    int resp = list[n%list.size()]; 
    list.clear();
    
    return resp;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {

    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << "\n";
    // std::cout << get_fibonacci_huge_naive(n, m) << " Naive \n";
}
