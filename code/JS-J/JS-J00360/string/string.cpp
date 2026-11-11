#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 10;
typedef long long ll;
typedef pair<int,int> PII;
//vector<vector<int>> adj;

int cnt[N];
char c[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> cnt[i] >> c[i];
    }
    ll ans = 0;
    for(int l = 1, r = n; l < r;) {
        int t = min(cnt[l], cnt[r]);
        cnt[l] -= t, cnt[r] -= t;
        if(c[l] != c[r]) {
            ans += t;
        }
        if(cnt[l] == 0) l ++;
        if(cnt[r] == 0) r --;
    }
    cout << ans;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
