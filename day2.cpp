#include <algorithm>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool sorted(vector<int> &v) {
    bool ok1 = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1]) {
            ok1 = false;
        }
    }
    bool ok2 = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] >= v[i - 1]) {
            ok2 = false;
        }
    }
    return ok1 or ok2;
}

bool check(vector<int> v) {
    if (!sorted(v)) {
        return false;
    }
    int c = 0;
    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i] - v[i - 1]) > 3) {
            c++;
        }
    }
    return c < 2;
}

vector<int> split(string &s) {
    vector<int> ans;
    int x = 0;
    for (char i: s) {
        if (i >= '0' and i <= '9') {
            x = x * 10 + i - '0';
        } else {
            ans.push_back(x);
            x = 0;
        }
    }
    ans.push_back(x);
    return ans;
}


int main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ans = 0;
    string s;
    while (getline(cin, s)) {
        if (check(split(s))) {
            ans++;
        }
    }
    cout << ans << endl;
}
