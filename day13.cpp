#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define int long long

pair<int, int> get_points(string &s) {
    const int first_plus = s.find('+');
    const int first_comma = s.find(',');
    const int second_plus = s.find('+', first_plus + 1);

    if (s.find("Prize") != string::npos) {
        const int first_equal = s.find('=');
        const int second_equal = s.find('=', first_equal + 1);
        // cout << s.substr(first_equal + 1, first_comma - first_equal - 1) << endl;
        // cout << s.substr(second_equal + 1) << endl;
        int x = stoll(s.substr(first_equal + 1, first_comma - first_equal - 1));
        int y = stoll(s.substr(second_equal + 1));



        return {x, y};
    }

    // cout << s.substr(first_plus + 1, first_comma - first_plus - 1) << endl;
    // cout << s.substr(second_plus + 1) << endl;
    int x = stoll(s.substr(first_plus + 1, first_comma - first_plus - 1));
    int y = stoll(s.substr(second_plus + 1));
    return {x, y};
}

vector<int> solve() {
    string s;
    char c;
    // Button A: X+94, Y+34
    // Button B: X+22, Y+67
    // Prize: X=8400, Y=5400
    getline(cin, s);
    if (s.empty()) return {};
    auto [ax, ay] = get_points(s);
    getline(cin, s);
    auto[bx, by] = get_points(s);
    getline(cin, s);
    auto [x, y] = get_points(s);
    getline(cin, s);
    return {ax, ay, bx, by, x, y};
}

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int ans = 0;
    vector<int> v;
    while (true) {
    solve:
        v = solve();
        if (v.empty()) break;
        int ax = v[0], ay = v[1], bx = v[2], by = v[3], x = v[4], y = v[5];
        cout << ax << " " << ay << " " << bx << " " << by << " " << x << " " << y << endl;
        for (int i = 100; i >= 0; i--) {
            for (int j = 0; j <= 100; j++) {
                if (bx * i + ax * j == x and by * i + ay * j == y) {
                    ans += i + j * 3;
                    goto solve;
                }
            }
        }
    }
    cout << ans << endl;
}
