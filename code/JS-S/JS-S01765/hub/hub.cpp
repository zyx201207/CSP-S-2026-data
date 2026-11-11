#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10;
int n, k, a[N], c, t;
vector<int> e[N];
void solve(){
    cout << n/3;
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--&&cin >> n >> k){
        for(int i=1, u, v;i<=n-1&&cin >> u >> v;i++){
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        solve();
    }
    return 0;
}
