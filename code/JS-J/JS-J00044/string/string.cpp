#include<bits/stdc++.h>
using namespace std;
long long a[200001], b[200001];
char c[200001], d[200001];
int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        b[i] = a[i], d[i] = c[i];
    }
    reverse(b + 1, b + 1 + n);
    reverse(d + 1, d + 1 + n);
    int l = 0, r = 0;
    long long ll = 0, rr = 0;
    while(true) {
        if(l == n && r == n) break;
        if(ll < rr && ll + a[l + 1] < rr) {
            if(c[l + 1] != d[r])
                ans += a[l + 1];
            ll += a[++l];
        } else if(ll > rr && ll > rr + b[r + 1]) {
            if(c[l] != d[r + 1])
                ans += b[r + 1];
            rr += b[++r];
        } else if(ll < rr && ll + a[l + 1] >= rr) {
            if(c[l + 1] != d[r])
                ans += (rr - ll);
            ll += a[++l];
        } else if(ll > rr && rr + b[r + 1] >= ll) {
            if(d[r + 1] != c[l])
                ans += (ll - rr);
            rr += b[++r];
        } else if(ll == rr)
            ll += a[++l];
    }
    cout << ans / 2;
    return 0;
}
