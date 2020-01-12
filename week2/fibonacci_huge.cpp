#include <iostream>
#include <vector>


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

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_efficient(n, m) << '\n';
    //std::cout << pisano_period(5) << '\n';

}
