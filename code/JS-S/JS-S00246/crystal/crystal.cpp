#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
typedef pair<int,int> PII;
const int INF = 0x3f3f3f3f;
//vector<vecotr<int>> adj(N);

ll a[N];
ll s[N];

void solve() {
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i];
    }
    ll ans = 0;
    for(ll r = 1, l = 1; r <= n; r ++) {
        while( ((r - l + 1) * a[r]) - (s[r] - s[l - 1]) > m) l ++;
        ans = max(ans, r - l + 1);
    }
    cout << ans;

}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
