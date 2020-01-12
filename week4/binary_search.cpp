#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>


using std::vector;

long long int binary_search(const vector<long long int> &a, int left, int right, int x) {
  //int left = 0, right = (int)a.size(); 
  //write your code here
  
  
  
  if(right >= left){

    int mid = floor(left + (right-left)/2);
    //std::cout << mid << "\n";

    if (x == a[mid])
    {
      return mid;
    }  

    else if(x < a[mid])
    {
      return binary_search(a, left, mid-1, x);
    }  

    else
    {
      return binary_search(a, mid+1, right, x );
    }  
   }

  else {return  - 1; }  

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long long int n;
  std::cin >> n;
  vector<long long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  int left = 0, right = (long long int)a.size();
  //std::cout<< right << "\n";
  
  long long int m;
  std::cin >> m;
  vector<long long int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, left, right, b[i]) << ' ';
  }
  
  /*
  int i;
  std::cin >> i;
  std::cout << binary_search(a, left, right, i) <<"\n";
  //binary_search(a, left, right, i);
  */
}
