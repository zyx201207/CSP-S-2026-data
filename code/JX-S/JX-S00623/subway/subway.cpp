#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int dp[100005][10005],w[100005],v[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=d;i++){
        cin>>v[i];
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;m-w[i]>0&&j<=n;j++){
            dp[i][j]=min(dp[i][j],dp[i][j]+v[i]);
        }
    }
    for(int i=1;i<=q;i++){
        cout<<dp[i][n]<<endl;
    }
    return 0;
}
