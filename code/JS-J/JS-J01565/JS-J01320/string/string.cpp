#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long stra;
    int w;
    char c;
};

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    string s = "0";

    for (int j = 0; j < n; j++) {
        int a;
        char c;
        cin >> a >> c;
        string t(a, c);
        s += t;
    }

    long long cnt = 0;

    if (s.size() % 2 == 0) {
        for (int i = 1; i <= s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 + 1 - i]) {
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}

/*n                                                                       
g++ string.cpp -o string -Wall -O2 -g 
time ./string

*/
