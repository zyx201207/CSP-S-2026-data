#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N],num[N];
int vec[N][N],dp[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>num[i];
        for(int j=1;j<=num[i];j++){
            cin>>a[i][j]>>t[i][j];
            dp[i][a[i][j]]=t[i][j];
            dp[a[i][j]][i]=t[i][j];
        }
    }
    //cout<<11111<<endl;
    for(int k=1;k<=m;k++){
        for(int u=1;u<=m;u++){
            for(int v=1;v<=m;v++){
                dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
            }
        }
    }
    //for(int i=1;i<=m;i++){
        //for(int j=1;j<=m;j++){
            //cout<<dp[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    while(q--){
        int x,y;
        cin>>x>>y;
        //cout<<1<<" :"<<dp[x][y]<<endl;
        cout<<dp[x][y]+w[x]+w[y]<<endl;
    }



    return 0;
}
