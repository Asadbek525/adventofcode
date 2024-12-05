#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> split(string s, char delimiter = ' ') {
    vector<int> result;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delimiter) {
            result.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    result.push_back(stoi(temp));
    return result;
}


int main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string x;
    map<int, set<int> > m;
    while (getline(cin, x)) {
        if (x.empty()) {
            break;
        }
        vector<int> temp = split(x, '|');
        m[temp[1]].insert(temp[0]);
    }
    long long ans = 0;
    while (getline(cin, x)) {
        int sign = 0;
        vector<int> temp = split(x, ',');
        vector<pair<int, int> > count(temp.size());
        for (int i = 0; i < temp.size(); i++) {
            int c = 0;
            for (int j = 0; j < temp.size(); j++) {
                if (m[temp[i]].count(temp[j])) {
                    c++;
                }
            }
            count[i] = {c, temp[i]};

            for (int j = i + 1; j < temp.size(); j++) {
                if (m[temp[i]].count(temp[j])) {
                    sign = 1;
                }
            }

        }
        sort(count.begin(), count.end());
        ans += sign * count[count.size()/2].second;
    }
    cout << ans << endl;
}
