#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long solve(long long l, long long r) {
    long long p = 0;
    for (int i = r-1; i > l; i--)
        p += a[r] - a[i];
    return p;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int l = 1, r = n;
    long long mid;
    while (l < r) {
        mid = (l+r) / 2;
        int tmp = solve(0, mid);
        //cout << tmp << endl;
        if (tmp == m) {
            while (a[mid+1] == a[mid]) mid++;
            cout << mid;
            return 0;
        }
        else if (tmp < m) l = mid+1;
        else r = mid - 1;
    }
    cout << mid;
    return 0;
}
