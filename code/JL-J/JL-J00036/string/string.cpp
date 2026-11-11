#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
int a[N];
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> c[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n == 2) {
        if (c[1] == c[2]) {
            cout << 0;
        }else {
            cout << min(a[1], a[2]);
        }
    }
    if (n == 3) {
        if (a[1] == a[3] && c[1] == c[3]) {
            cout << 0;
        }else {
            if (c[1] != c[3]) {
                cout << min(a[1], a[3]);
            }else {
                cout << abs(a[1] - a[3]);
            }
        }
    }
    return 0;
}
