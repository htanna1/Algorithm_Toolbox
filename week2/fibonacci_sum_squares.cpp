#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int pisano_period(int m) {

    int previous = 0;
    int current  = 1;

    for (int i = 0 ; i< m*m ; i++)
    {
        int new_current = (previous + current) % m ;
        previous = current;
        current = new_current;

        if (previous == 0 and current == 1)
        {
            return i+1;
        }   
    }   
}

long long get_fibonacci_huge_efficient(long long n, long long m) {

    //long long pis_p = pisano_period(m);
    //pissano period time after which the sequence repeats itself
    //F(2015) mod 3 : 2015 mod 8 = 7 hence we need to calculate only F(7) mod 3 where 8 is pisano_p of 3
    long long new_fib = n % pisano_period(m);

    long long previous = 0;
    long long current = 1;

    // this loop is to calculate F(7) mod 3 from above example
    //using the fact that F(n) mod m = (F(n-1) + F(n-2)) mod m
    for(int i = 1; i< new_fib; i++)
    {
        int new_current = (previous + current) % m;
        previous = current;
        current = new_current;
    }

    return current % m ;

}

int fibonacci_sum_squares_efficient(long long n) {

    //it is f(n+1) * f(n)
    int first_num = get_fibonacci_huge_efficient(n+1,10);

    int second_num = get_fibonacci_huge_efficient(n,10);

    return (first_num * second_num)%10 ;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n) << "\n";
    std::cout << fibonacci_sum_squares_efficient(n) << "\n";
}
