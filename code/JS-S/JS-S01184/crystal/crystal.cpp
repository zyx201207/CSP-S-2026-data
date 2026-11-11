#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5+5;
int a[N];
ll n, m, st = 1, tot = 0, ans = -1LL;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (ll i = 2; i <= n; ++i){
        tot += (ll) (a[i] - a[i - 1]) * (i - st);
        while (tot > m){
            ans = max(ans, i - st);
            tot -= (a[i] - a[st]);
            st += 1;
        }
    }
    cout << (ans == -1LL ? n : ans);
    return 0;
}
