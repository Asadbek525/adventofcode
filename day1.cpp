#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {

    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<int, int> l1,l2;
    vector<int> v1;
    int x1, x2;
    while(cin >> x1) {
        l1[x1]++;
        v1.push_back(x1);
        cin >> x2;
        l2[x2]++;
    }
    long long ans = 0;
    for (auto x: v1) {
        ans += x * l2[x];
    }
    cout << ans << endl;
}