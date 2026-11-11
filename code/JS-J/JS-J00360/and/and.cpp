#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 10;
typedef long long ll;
typedef pair<int,int> PII;
//vector<vector<int>> adj;

//int a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 31; i >= 0; i --) {
        int cnt = 0;
        vector<ll> b;
        for(int j = 0; j < a.size(); j ++) {
            if(((a[j] >> i) & 1) == 0) continue;
            b.push_back(a[j]);
        }
        if(b.size() >= m) swap(a, b);
    }

    ll ans = a[0];
    for(int i = 1; i < a.size(); i ++) {
        ans = ans & a[i];
    }
    cout << ans;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
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
