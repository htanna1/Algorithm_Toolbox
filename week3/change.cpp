#include <iostream>
#include <vector>

int get_change(int m) {
  //write your code here
	int small = 1;
	int medium = 5;
	int large = 10;
	int i = m;
	int sum = 0;
	while (i)
	{
			// first always check if the number is > large one
			if(i >= large) 
			{	
				i = i - large;	
				//break;			
			}

			else if(i >= medium)
			{
			 	i = i - medium;
			}	
			

			else if (i >= small)
			{ 
				i = i - small;
			}	
			

		

		sum += 1;

	} 

  return sum;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
