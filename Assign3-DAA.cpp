//Fractional knapsack problem using Greedy Algorithm

#include <bits/stdc++.h>
using namespace std;

struct WtPft {
    int wt;
    int pft;
};

bool cmp(WtPft l, WtPft r) {
    double x = static_cast<double>(l.pft) / l.wt;
    double y = static_cast<double>(r.pft) / r.wt;
    return x > y;
}

int helperFunc(vector<WtPft>& vec, int n, int w) {
    sort(vec.begin(), vec.end(), cmp);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (w >= vec[i].wt) {
            res += vec[i].pft;
            w -= vec[i].wt;
        } else {
            double fraction = static_cast<double>(w) / vec[i].wt;
            res += static_cast<int>(fraction * vec[i].pft);
            break;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Enter the total number of weights: ";
    cin >> n;

    int w;
    cout << "Enter the value of maximum weight: ";
    cin >> w;

    vector<WtPft> vec(n);
    cout << "Enter the weights and profits for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i].wt >> vec[i].pft;
    }

    int maxProfit = helperFunc(vec, n, w);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
