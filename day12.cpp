#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define int long long


int calculate_area(vector<vector<char> > &v, vector<vector<bool> > &used, int i, int j) {
    if (used[i][j]) return 0;
    used[i][j] = true;
    int area = 1;
    if (i + 1 < v.size() and v[i + 1][j] == v[i][j]) {
        area += calculate_area(v, used, i + 1, j);
    }
    if (i - 1 >= 0 and v[i - 1][j] == v[i][j]) {
        area += calculate_area(v, used, i - 1, j);
    }
    if (j + 1 < v[0].size() and v[i][j + 1] == v[i][j]) {
        area += calculate_area(v, used, i, j + 1);
    }
    if (j - 1 >= 0 and v[i][j - 1] == v[i][j]) {
        area += calculate_area(v, used, i, j - 1);
    }
    return area;
}

int calculate_corners(vector<vector<char> > &v, vector<vector<bool> > &used, int i, int j) {
    if (used[i][j]) return 0;
    used[i][j] = true;
    int corners = 0;

    // is right top corner
    if (
        i - 1 >= 0 and j + 1 < v[0].size() and v[i - 1][j] != v[i][j] and v[i][j + 1] != v[i][j] or
        i - 1 >= 0 and j + 1 < v[0].size() and v[i - 1][j] == v[i][j] and v[i][j + 1] == v[i][j] and v[i - 1][j + 1] != v[i][j] or
        i == 0 and j == v[0].size() - 1 or
        i == 0 and j + 1 < v[i].size() and v[i][j + 1] != v[i][j] ||
        i - 1 >= 0 and j == v[i].size() - 1 and v[i - 1][j] != v[i][j]
        )
        corners += 1;

    // is left top corner
    if (
        i - 1 >= 0 and j - 1 >= 0 and v[i - 1][j] != v[i][j] and v[i][j - 1] != v[i][j] or
        i - 1 >= 0 and j - 1 >= 0 and v[i - 1][j] == v[i][j] and v[i][j - 1] == v[i][j] and v[i - 1][j - 1] != v[i][j] or
        i == 0 and j == 0 ||
        i == 0 and j - 1 >= 0 and v[i][j - 1] != v[i][j] or
        i - 1 >= 0 and j == 0 and v[i - 1][j] != v[i][j]
        )
        corners += 1;

    // is right bottom corner
    if (
        i + 1 < v.size() and j + 1 < v[0].size() and v[i + 1][j] != v[i][j] and v[i][j + 1] != v[i][j] or
        i + 1 < v.size() and j + 1 < v[0].size() and v[i + 1][j] == v[i][j] and v[i][j + 1] == v[i][j] and v[i + 1][j + 1] != v[i][j] or
        i == v.size() - 1 and j == v[0].size() - 1 or
        i == v.size() - 1 and j + 1 < v[i].size() and v[i][j + 1] != v[i][j] or
        i + 1 < v.size() and j == v[i].size() - 1 and v[i + 1][j] != v[i][j]
        )
        corners += 1;

    // is left bottom corner
    if (
        i + 1 < v.size() and j - 1 >= 0 and v[i + 1][j] != v[i][j] and v[i][j - 1] != v[i][j] or
        i + 1 < v.size() and j - 1 >= 0 and v[i + 1][j] == v[i][j] and v[i][j - 1] == v[i][j] and v[i + 1][j - 1] != v[i][j] or
        i == v.size() - 1 and j == 0 or
        i == v.size() - 1 and j - 1 >= 0 and v[i][j - 1] != v[i][j] or
        i + 1 < v.size() and j == 0 and v[i + 1][j] != v[i][j]
        )
        corners += 1;






    if (i + 1 < v.size() and v[i + 1][j] == v[i][j]) {
        corners += calculate_corners(v, used, i + 1, j);
    }

    if (i - 1 >= 0 and v[i - 1][j] == v[i][j]) {
        corners += calculate_corners(v, used, i - 1, j);
    }

    if (j + 1 < v[0].size() and v[i][j + 1] == v[i][j]) {
        corners += calculate_corners(v, used, i, j + 1);
    }

    if (j - 1 >= 0 and v[i][j - 1] == v[i][j]) {
        corners += calculate_corners(v, used, i, j - 1);
    }


    return corners;
}

int calculate_price(
    vector<vector<char> > &v,
    vector<vector<bool> > &used_area,
    vector<vector<bool> > &used_perimeter,
    int i,
    int j) {
    if (used_area[i][j]) return 0;
    int area = calculate_area(v, used_area, i, j);
    int sides = calculate_corners(v, used_perimeter, i, j);
    return area * sides;
}


signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string x;
    vector<vector<char> > v;
    while (cin >> x) {
        vector<char> temp;
        for (const char i: x) {
            temp.push_back(i);
        }
        v.push_back(temp);
    }

    vector used_area(v.size(), vector(v[0].size(), false));
    vector used_perimeter(v.size(), vector(v[0].size(), false));
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            ans += calculate_price(v, used_area, used_perimeter, i, j);
        }
    }
    cout << ans;
}
