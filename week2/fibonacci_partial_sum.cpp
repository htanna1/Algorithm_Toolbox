#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fibonacci_sum_efficient(long long n) {

    //n = (n+2) % 60;
    
//since we need sum of 1st n fibonnaci numbers which is equal to F(n+2)-1 
//so we have to calculate for f(n+2) and not f(n) while doing the addtion routine

    
    std::vector<int> fiblist(n+1);

    fiblist[0] = 0;
    fiblist[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        /* code */
        fiblist[i] = (fiblist[i-1]%10 + fiblist[i-2]%10)%10; //since we need the sum of last digit only
    }

    if (fiblist[n] == 0) { return 9;}
    return (fiblist[n]%10 -1);

}


long long get_fibonacci_partial_sum_efficient(long long from, long long to) {

    to = (to+2)%60;
    //std::cout << to << "\n";
    int sum_to = fibonacci_sum_efficient(to);
    //std::cout << sum_to << "\n";

    from = (from+1)%60;
    //std::cout << from << "\n";
    int sum_from = fibonacci_sum_efficient(from);
    //std::cout << sum_from << "\n";

    int final_sum = (sum_to+ 10 - sum_from)%10;

    return final_sum;
    
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_efficient(from, to) << '\n';
    //get_fibonacci_partial_sum_efficient(from, to);
}
