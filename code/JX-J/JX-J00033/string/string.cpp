#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
struct node {
    ll number;
    string val;
}c[N];
ll n;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> c[i].number >> c[i].val;
    }
    ll ans = 0;
    ll l = 1,li = 1;
    ll r = n,ri = 1;
    while (l < r) {
        int t = c[l].number - li + 1,p = c[r].number - ri + 1;
        // cout << t << ' ' << p << '\n';
        if (c[l].val != c[r].val) {
            ans += min(t,p);
        }
        if (t == p) {
            li = ri = 1;
            l++,r--;
        }
        else if (t > p) {
            li = c[l].number - (t - p) + 1;
            ri = 1;
            r--;
        }
        else {
            ri = c[r].number - (p - t) + 1;
            li = 1;
            l++;
        }
    }
    cout << ans;
    return 0;
}
