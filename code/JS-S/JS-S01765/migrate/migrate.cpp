#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n, d, a[N], dp[N][N], num[N][N], c, t;
void solve(){
    memset(dp, 0, sizeof(dp));
    memset(num, 0, sizeof(num));
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(a[r]-a[l]<=d){
                dp[l][r]=num[l][r]=1;
                continue;
            }
            for(int k=l+1;k<=r-1;k++){
                int x=min(dp[l][k]+dp[k][r]+1, dp[l][r]);
                if(x<dp[l][r]) num[l][r]=1;
                else num[l][r]++;
                dp[l][r]=x;
            }
        }
    }
    int cnt=0;
    for(int l=1;l<=n;l++){
        for(int r=l+1;r<=n;r++) if(num[l][r]==2) cnt++;
    }
    cout << cnt << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--&&cin >> n >> d){
        for(int i=1;i<=n;i++) cin >> a[i];
        solve();
    }
    return 0;
}
