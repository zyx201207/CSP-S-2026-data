#include <bits/stdc++.h>

using namespace std;

long long n;
string s;
struct node {
    long long x;
    char c;
} a[1145140];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].c;
    }

    if (n == 1) {
        cout << 0;
        return 0;
    } else if (n == 2) {
        if (a[1].c == a[2].c) cout << 0;
        else cout << min(a[1].x, a[2].x);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i].c != a[j].c) {
                cout << a[i].x;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}
















