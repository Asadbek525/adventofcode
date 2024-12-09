#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define int long long

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ans = 0;

    string x;
    vector<vector<char>> v;
    while (getline(cin, x)) {
        vector<char> temp;
        for (char i: x) {
            temp.push_back(i);
        }
        v.push_back(temp);
    }

}
