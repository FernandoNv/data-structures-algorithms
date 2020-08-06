#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;


int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefills = 0;
    int currentRefill = 0;
    int n = stops.size() - 1; //number of petrol stations

    //goes until reaches the destination at n
    while(currentRefill < n){
        int lastRefill = currentRefill;
        while(currentRefill < n && stops[currentRefill + 1] - stops[lastRefill] <= tank)
            currentRefill++;
        if(currentRefill == lastRefill)
            return -1;
        //test if it hasn't reached the destination yet
        if(currentRefill < n)
            numRefills++;
    }

    return numRefills;
}


int main() {

    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2, 0);
    for (int i = 1; i <= n; ++i)
        cin >> stops.at(i);
    stops[n+1] = d;
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;

}
