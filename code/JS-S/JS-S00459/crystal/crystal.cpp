#include<bits/stdc++.h>
using namespace std;

long long a[500005];
bool f, f1;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long t = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i-1]) {
            f = 1;
        }
        t = a[i-1] - a[i-2];
        if(t != a[i] - a[i-1]) {
            f1 = 1;
        }
    }
    if (f == 0 || m == 0) {
        cout << n << '\n';
        return 0;
    }
    if(f1 == 0) {
            int i = 1;
        while(1) {
            i = 1;
            m -= i*t;
            i++;
            if(m <= 0) {
                break;
            }
        }
        cout << i-1 << '\n';
        return 0;
    }
    return 0;
}
