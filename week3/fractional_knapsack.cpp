#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class KnapSack {

private:
	int value_knap;
	int weight_knap;
	int val_p_weight;

public:
	KnapSack() {};

	KnapSack(int value, int weight, double valuePerWeight) {
      value_knap = value;
      weight_knap = weight;
      val_p_weight = valuePerWeight;
    }

    int get_value() {

    	return value_knap;
    }

    int get_weight() {

    	return weight_knap;
    }

    int get_val_p_wei() {

    	return val_p_weight;
    }
};


bool compare_vpw(KnapSack a1, KnapSack a2) {
  return a1.get_val_p_wei() > a2.get_val_p_wei();
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<KnapSack> knapitems;
  int values1,weights1 = 0;

  for (int i = 0; i < weights.size(); i++)
  {
  	knapitems.push_back(KnapSack(values[i], weights[i], (double)values[i]/(double)weights[i]));
  	values1 += values[i];
  	weights1 += weights[i];
  }


  if (weights1 <= capacity) {
    return values1;
  }


sort(knapitems.begin(), knapitems.end(), compare_vpw);

int weight_again = 0;

  for (int i = 0; i < knapitems.size(); i++) {
    if (weight_again + knapitems[i].get_weight() < capacity) {
      weight_again +=knapitems[i].get_weight();
      value +=knapitems[i].get_value();
    } else if (weight_again +knapitems[i].get_weight() == capacity) {
      value +=knapitems[i].get_value();
      break;
    } else {  // if it's greater, figure out how to fraction the difference and add it
      int weightDelta = capacity - weight_again;
      value +=knapitems[i].get_val_p_wei() * (double)weightDelta;
      break;
    }
  }

  return value;




}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(4);
  std::cout << std::fixed << optimal_value << std::endl;
//  std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
  return 0;
}