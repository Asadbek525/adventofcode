#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define int long long

void strip(string &s) {
    while (s.size() and s[0] == ' ') {
        s = s.substr(1);
    }
    while (s.size() and s[s.size() - 1] == ' ') {
        s = s.substr(0, s.size() - 1);
    }
}

int concate(int &a, int &b) {
    return stoll(to_string(a) + to_string(b));
}

vector<string> split(const string &s, char delimiter = ' ') {
    vector<string> result;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delimiter) {
            result.push_back(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }
    strip(temp);
    result.push_back(temp);
    return result;
}


bool ok(int res, vector<int> temp) {
    int n = 1;
    for (int i = 0; i < temp.size() - 1; i++) {
        n *= 3;
    }
    for (int i = 0; i < n; i++) {
        int sum = temp[0];
        int k = i;
        for (int j = 0; j < temp.size() - 1; j++) {
            if (k % 3 == 0) {
                sum += temp[j + 1];
            } else if (k % 3 == 1) {
                sum = concate(sum, temp[j + 1]);
            } else {
                sum *= temp[j + 1];
            }
            if (sum > res) {
                break;
            }
            k /= 3;
        }
        if (sum == res) {
            return true;
        }
    }
    return false;
}

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ans = 0;
    string x;
    while (getline(cin, x)) {
        auto s = split(x, ':');
        int res = stoll(s[0]);
        auto v = split(s[1], ' ');
        vector<int> temp;
        for (auto y: v) {
            temp.push_back(stoll(y));
        }
        if (ok(res, temp)) {
            ans += res;
        }
    }
    cout << ans << endl;
}
