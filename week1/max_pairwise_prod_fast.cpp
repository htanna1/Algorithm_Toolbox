#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers)
{
	int first = -1;
	
	for(int i =0; i<numbers.size(); ++i)
	{
		if ((first == -1) || (numbers[i] > numbers[first]))
		{
			first = i;
		}	

	}	

	int second = -1; 
	//std::cout << numbers[first] << "\n";
	for(int j =0; j<numbers.size(); ++j)
	{
		if ((j != first)  && ((second == -1) || (numbers[j] > numbers[second])))
		{
			//std::cout<< i ;
			second = j;
		}	

	}	
	//max_product = numbers[first]*numbers[second];
	//std::cout << second;
	return ((long long) (numbers[first]) * numbers[second]);
	//std::cout<< first << "\n" << second <<"\n";
	//std::cout<< numbers[first] << "\n" << numbers[second] <<"\n";
}


int main(int argc, char const *argv[])
{
	int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
	return 0;

}