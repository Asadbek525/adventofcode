#include <iostream>
#include <regex>
#include <string>
#include <valarray>

using namespace std;


int main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s = "";
    string x;
    while (getline(cin, x)) {
        s += x;
    }
    regex pattern(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\))");
    smatch matches;
    long long ans = 0;
    int sign = 1;
    const auto begin = sregex_iterator(s.begin(), s.end(), pattern);
    const auto end = sregex_iterator();

    for (auto it = begin; it != end; ++it) {
        const smatch &match = *it;
        ans += stoi(match[1]) * stoi(match[2]) * sign;
    }
    // Searching for matches in the input string
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 4) == "do()" and sign == -1) {
            sign = 1;
        }
        else if (s.substr(i, 7) == "don't()" and sign == 1) {
            sign = -1;
        } else {
            continue;
        }
        const auto begin = sregex_iterator(s.begin() + i, s.end(), pattern);
        const auto end = sregex_iterator();
        for (auto it = begin; it != end; ++it) {
            const smatch &match = *it;
            // cout << match[1] << " " << match[2] << " " << sign << " " << stoi(match[1]) * stoi(match[2]) * sign << " " << ans << endl;
            ans += stoi(match[1]) * stoi(match[2]) * sign;
        }
    }
    cout << ans << endl;
}
