#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


//last digit of fibonacchi sequence has a pattern of 60 so pisano period of mod 10 is 60
// this means you can mod the number by 60 recursively 1st and then do the addition routine

/*long long recursive_mod_sixty(long long n) {

    if (n > 60)
    {
        return recursive_mod_sixty(n%60);
    }    
    else return n;
}
*/


int fibonacci_sum_efficient(long long n) {

    n = (n+2) % 60;
    
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
    return (fiblist[n]%10 - 1);

}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << "\n";
    //std::cout << recursive_mod_sixty(n) << "\n";
    std::cout << fibonacci_sum_efficient(n) << "\n";
}
