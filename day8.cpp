#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define int long long

void colorize(pair<int, int> &a, pair<int, int> &b, vector<vector<bool> > &visited) {
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int dx = x2 - x1;
    int dy = y2 - y1;
    for (int i = -1000; i <= 1000; i++) {
        int x = x1 + i * dx;
        int y = y1 + i * dy;
        if (x >= 0 and x < visited.size() and y >= 0 and y < visited[0].size()) {
            visited[x][y] = true;
        }
    }
}

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string x;
    vector<vector<char> > v;
    map<char, vector<pair<int, int> > > mp;
    while (getline(cin, x)) {
        vector<char> temp;
        for (char i: x) {
            temp.push_back(i);
        }
        v.push_back(temp);
    }
    const int n = v.size();
    const int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '.') {
                mp[v[i][j]].push_back(make_pair(i, j));
            }
        }
    }
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for (auto [c, a]: mp) {
        for (auto x: a) {
            for (auto y: a) {
                if (x != y) {
                    colorize(x, y, visited);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += visited[i][j];
        }
    }
    cout << ans << endl;
}
