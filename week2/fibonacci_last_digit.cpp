#include <iostream>
#include <cassert>
#include <vector>

/*int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
*/
int get_fibonacci_last_digit_fast(int n) {

    std::vector<int> fiblist(n+1);

    fiblist[0] = 0;
    fiblist[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        /* code */
        fiblist[i] = (fiblist[i-1] + fiblist[i-2]) % 10;
    }

    return fiblist[n];
}

int main() {
    int n;
    std::cin >> n;
    //std::cout << get_fibonacci_last_digit_naive(n) << "\n";
    std::cout << get_fibonacci_last_digit_fast(n) << "\n";

    }
