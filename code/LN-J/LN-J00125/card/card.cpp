#include <bits/stdc++.h>
using namespace std;
int n,m,b[300005],vis[300005];
char a[500005];
string dp[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    b[a[n]]++;
    dp[n]=a[n];
    vis[a[n]]=n;
    for(int i=n-1;i>=1;i--){
        if(vis[a[i]]){
            dp[i]=dp[vis[a[i]]];
            vis[a[i]]=i;
        }
        else{
            dp[i]=dp[i+1];
            dp[i]+=a[i];
            vis[a[i]]=i;
        }
        for(int j=0;j<dp[i].length();j++){
            b[dp[i][j]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << b[i] << " ";
    }
    return 0;
}