#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n;
ll m;
ll a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int mx = 1;
    for (int i = 2; i <= n; i++) {
        int t = 1;
        ll x = m;
        for (int j = i - 1; j >= 1; j--) {
            if (a[i] - a[j] <= x) {
                x = x - (a[i] - a[j]);
                t++;
            }
        }
        mx = max(mx, t);
    }
    cout << mx;
    return 0;
}
