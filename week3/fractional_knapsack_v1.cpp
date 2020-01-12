#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;



int get_max_index(vector<int> weights, vector<int> values) {

	int max_fraction = 0 ;
	int max_index = 0;

	for(int i=0; i < weights.size(); i++)
	{
		if( weights[i] !=0 &&  ((double) values[i])/weights[i] > max_fraction )
		{
			max_fraction = ((double) values[i])/weights[i] ;
			max_index = i;
		}	
	}	

	return max_index;


}



double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

//one cannot keep looping until the capacity because capacity can be very large, this will result in a long loop
    //while (capacity)

    for(int i =0; i<weights.size() && capacity > 0; i++)
    {
    	int i1 = get_max_index(weights, values);
    	int multiplier = min(weights[i1], capacity);
    	value += multiplier *  ((double) values[i1])/weights[i1] ;
    	capacity -= multiplier;
    	weights[i1] = 0;
    }



    return value;

}



int main() {

	int n;
	int capacity;
	cin >> n >> capacity;

	vector<int> values(n);
	vector<int> weights(n);

	vector< pair<int, int> > value_weight;
	vector< pair<double, int> > fraction_weight;

	//pair<int, int> p1;

	//p1.first = 0;

	for (int i = 0; i < n; i++) {
        //std::cin >> values[i] >> weights[i];
        cin >> value_weight[i].first >> value_weight[i].second;

        fraction_weight[i].first = ((double) value_weight[i].first)/value_weight[i].second;
        fraction_weight[i].second = value_weight[i].second;

    }

   // double optimal_value = get_optimal_value(capacity, weights, values);

    //cout.precision(10);
    //cout << optimal_value << std::endl;

    int num_items = value_weight.size();
    std::sort(fraction_weight.begin(),fraction_weight.end(),greater<pair <double, int> >());

    double final_value = 0.0;

	for(int i =0; i < num_items && capacity > 0 ; i++)
	{

	if ( capacity >= fraction_weight[i].second)
	{
      final_value += fraction_weight[i].first * fraction_weight[i].second ;
      capacity -= fraction_weight[i].second;
    }  
    else
    {
      final_value += fraction_weight[i].first * capacity;
      capacity -= capacity;
    }  
	}  

	cout << final_value << std::endl;

    return 0;
  
}

