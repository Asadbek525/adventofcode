#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define int long long

map<pair<int, int>, int> m;

int blink(int n, int c) {
    if (c == 0) return m[{n, 0}] = 1;
    if (m[{n, c}]) return m[{n, c}];
    if (n == 0) {
        return m[{n, c}] = blink(1, c - 1);
    }

    if (to_string(n).size() % 2 == 0) {
        string s = to_string(n);
        int first_half = stoll(s.substr(0, s.size() / 2));
        int second_half = stoll(s.substr(s.size() / 2));
        return m[{n, c}] = blink(first_half, c - 1) + blink(second_half, c - 1);
    }

    return m[{n, c}] = blink(n * 2024, c - 1);
}

vector<int> split(const string &s, const char delimiter = ' ') {
    vector<int> result;
    string temp;
    for (char i : s) {
        if (i == delimiter) {
            result.push_back(stoll(temp));
            temp.clear();
        } else {
            temp += i;
        }
    }
    result.push_back(stoll(temp));
    return result;
}

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string x;
    getline(cin, x);
    vector<int> v = split(x);
    int ans = 0;
    for (auto n: v) {
        ans += blink(n, 75);
    }
    cout << ans << endl;
}
