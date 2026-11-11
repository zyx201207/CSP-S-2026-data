#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
bool vis[N][31],surv[N];
void solve(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i++){
        surv[i] = 1;
        int t; cin >> t;
        for(int j = 0;j <= 30;j++){
            if(t & (1LL << j)) vis[i][j] = 1;
        }
    }
    int ans = 0;
    for(int j = 30;j >= 0;j--){
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i][j] && surv[i]) cnt++;
        }
        if(cnt >= m){
            ans += (1LL << j);
            for(int i = 1;i <= n;i++){
                if(surv[i] && !vis[i][j]) surv[i] = 0;
            }
        }
    }
    cout << ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1;
    while(T--) solve();
}

// expect 100 pts