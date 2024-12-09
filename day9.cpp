#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define int long long

struct File {
    int index;
    int size;

    File() {
        index = 0;
        size = 0;
    }

    File(int index, int size) {
        this->index = index;
        this->size = size;
    }
};

signed main() {
    // file intput and output
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> v;
    string x;
    cin >> x;
    vector<File> spaces;
    vector<File> files;
    int index = 0;
    for (int i = 0; i < x.size(); i++) {
        int size = x[i] - '0';
        File f = File(index, size);
        if (i % 2) {
            spaces.push_back(f);
        } else {
            files.push_back(f);
        }
        index += size;
    }


    for (int i = files.size() - 1; i >= 0; i--) {
        for (int j = 0; j < spaces.size(); j++) {
            File f = spaces[j];
            if (f.size >= files[i].size and i > j) {
                files[i].index = spaces[j].index;
                spaces[j].size -= files[i].size;
                spaces[j].index += files[i].size;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < files.size(); i++) {
        auto f = files[i];
        cout << i << " " << f.index << " " << f.size << endl;
        for (int j = f.index; j < f.index + f.size; j++) {
            ans += j * i;
        }
    }
    cout << ans << endl;
}
