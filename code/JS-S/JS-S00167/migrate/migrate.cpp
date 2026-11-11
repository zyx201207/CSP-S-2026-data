#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4+10;
int a[N],dp[N][N];
void solve(){
    memset(dp,0,sizeof dp);
    int n,d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)cin >> a[i];
    if(a[1]<0){
        for(int i = 1; i <= n; i++){
            a[i]+=abs(a[1]);
        }
    }
    bool fa = true,fb = true;
    for(int i = 2; i <= n-1; i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            fa=false;
            break;
        }
    }
    if(d==1||d>n){
        cout << "0\n";
        return;
    }
    if(fa){
        if(d<a[2]-a[1]||d>n){
            cout << "0\n";
            return;
        }else{
            cout << (a[n]-a[1])/d<<'\n';
            return ;
        }
    }
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            if(a[j]>=d)dp[i][j]+=dp[i][a[j]-d];
            //dp[i][j] = (a[j]-a[i])/d+dp[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j]==2)ans++;
        }
    }
    cout << ans << '\n';
}
int main (){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}
