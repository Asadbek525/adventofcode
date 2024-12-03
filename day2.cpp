#include <algorithm>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool sorted(vector<int> &v) {
    bool ok1 = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) {
            ok1 = false;
        }
    }
    bool ok2 = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) {
            ok2 = false;
        }
    }
    return ok1 or ok2;
}

bool check(vector<int> v) {
    if (!sorted(v)) {
        return false;
    }
    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i] - v[i - 1]) == 0 or abs(v[i] - v[i - 1]) > 3) {
            return false;
        }
    }
    return true;
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

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ans = 0;
    string s;
    while (getline(cin, s)) {
        vector<int> v = split(s);
        if (check(v)) {
            ans++;
        } else {
            for (int i = 0; i < v.size(); i++) {
                vector<int> u(v.size() - 1);
                for (int j = 0; j < v.size(); j++) {
                    if (j < i) {
                        u[j] = v[j];
                    } else if (j > i) {
                        u[j - 1] = v[j];
                    }
                }
                if (check(u)) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
