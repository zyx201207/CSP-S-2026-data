#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int st[100010],ta[100010],t[500010];
int dp[100010][100010];
int main(){
    struct loa{
        int a;
        int t1;
    }l[1000010];
    cin>>c>>n>>m>>d>>q;
    int k;
    for (int i=1;i<=m;i++){
        cin>>t[i];
    }
    cin>>k;
    for (int j=1;j<=n;j++){
        for (int i=1;i<=k;i++){
            cin>>l[i].a>>l[i].t1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>st[i]>>ta[i];
    }
    dp[1][1]=st[1];
    for (int i=1;i<=n;i++){
        for (int j=dp[i][i];j<=n;j++){
            dp[i][i+1]=dp[st[i]][j];
            dp[i+1][1]=dp[st[i]][j-1];
            dp[i][i]=min(dp[i][i+1],dp[i+1][i]+dp[i][i]);
        }
    }
    struct op{
        int x;
        int y;
    };
    for (int i=1;i<=q;i++){
        cout<<dp[n-i][n-i];
    }
    return 0;
}
