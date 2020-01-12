#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    //int max_stops = 0;
    //num_refill contains the number of refills we have already made
    //cur refill is position in the array
    int cur_refill = 0;
    int num_refill = 0;
    stops.insert(stops.begin(),0);
    stops.push_back(dist);
    int n = stops.size();
    int last_refill = 0;

    while( cur_refill <= n)
    {
        last_refill = cur_refill;

        while( cur_refill <= n && stops[cur_refill+1] - stops[last_refill] <= tank )
        {
            cur_refill += 1;
        }

        if (cur_refill == last_refill) { return -1 ;}

        if (cur_refill <= n) { num_refill += 1;}

    } 

    return num_refill;
    /*
    if(m >= dist)
    {
        return max_stops;
    }    
    else if(dist > m && m >= (stops[i] - stops[i-1]))
    {

    }    
    */


    //return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
