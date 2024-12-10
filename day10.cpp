#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define int long long


void dfs(int i, int j, vector<vector<int> > &v, vector<vector<int> > &dp) {
    dp[i][j] += 1;
    if (i + 1 < v.size() and v[i + 1][j] == v[i][j] + 1)
        dfs(i + 1, j, v, dp);
    if (i - 1 >= 0 and v[i - 1][j] == v[i][j] + 1)
        dfs(i - 1, j, v, dp);
    if (j + 1 < v[0].size() and v[i][j + 1] == v[i][j] + 1)
        dfs(i, j + 1, v, dp);
    if (j - 1 >= 0 and v[i][j - 1] == v[i][j] + 1)
        dfs(i, j - 1, v, dp);
}

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<vector<int> > v;
    string x;
    while (cin >> x) {
        vector<int> temp;
        for (const char i: x) {
            temp.push_back(i - '0');
        }
        v.push_back(temp);
    }

    vector<pair<int, int> > positionsZero;
    vector<pair<int, int> > positionsNine;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 0) {
                positionsZero.emplace_back(i, j);
            } else if (v[i][j] == 9) {
                positionsNine.emplace_back(i, j);
            }
        }
    }

    vector dp(v.size(), vector<int>(v[0].size(), 0));

    for (auto [x, y]: positionsZero) {
        dfs(x, y, v, dp);
    }

    int ans = 0;
    for (auto [x, y]: positionsNine) {
        ans += dp[x][y];
    }

    cout << ans << endl;
}
