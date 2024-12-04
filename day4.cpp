#include <iostream>
#include <string>
#include <vector>

using namespace std;


void print(vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
}

void print(vector<vector<char> > v) {
    for (int i = 0; i < v.size(); i++) {
        print(v[i]);
        cout << endl;
    }
}

bool check(vector<vector<char> > &v, int i, int j) {
    if (i + 2 >= v.size() or j + 2 >= v[i].size()) {
        return false;
    }
    string diagonal = string() + v[i][j] + v[i + 1][j + 1] + v[i + 2][j + 2];
    string second_diagonal = string() + v[i][j + 2] + v[i + 1][j + 1] + v[i + 2][j];
    if ((diagonal == "MAS" or diagonal == "SAM") and (second_diagonal == "MAS" or second_diagonal == "SAM")) {
        return true;
    }
    return false;
}

int main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string x;
    vector<vector<char> > v;
    while (getline(cin, x)) {
        vector<char> temp;
        for (char i: x) {
            temp.push_back(i);
        }
        v.push_back(temp);
    }
    int xmasCount = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (check(v, i, j)) {
                xmasCount++;
            }
        }
    }
    // for (int i = 0; i < v.size(); i++) {
    //     for (int j = 0; j < v[i].size(); j++) {
    //         if (visited[i][j]) {
    //             cout << v[i][j];
    //         } else {
    //             cout << ".";
    //         }
    //     }
    //     cout << endl;
    // }
    cout << xmasCount << endl;
}
