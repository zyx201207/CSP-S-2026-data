#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510;
ll c,n,m,d,q;
ll dp[1010][1010];
ll w[N];
ll a[N],t[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c<=8){
        memset(dp,0x3f,sizeof dp);
        for(int i=1;i<=m;i++){
            dp[i][i]=0;
        }
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){

            ll kk;
            cin>>kk;
            for(int i=1;i<=kk;i++){
                cin>>a[i]>>t[i];
            }
            for(int i=1;i<=kk;i++){
                for(int j=i+1;j<=kk;j++){
                    dp[a[i]][a[j]]=dp[a[j]][a[i]]=min(dp[a[i]][a[j]],t[i]+t[j]);
                }
            }
        }

        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        while(q--){
            ll x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+dp[x][y]<<endl;
        }
        return 0;
    }
    if(c>=9&&c<=11){
        memset(dp,0x3f,sizeof dp);
        for(int i=1;i<=m;i++){
            dp[i][i]=0;
        }
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            ll kk;
            cin>>kk;
            ll a1,t1,a2,t2;
            cin>>a1>>t1>>a2>>t2;
            dp[a1][a2]=dp[a2][a1]=t1+t2;
        }
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        while(q--){
            ll x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+dp[x][y]<<endl;
        }
        return 0;
    }
    memset(dp,0x3f,sizeof dp);
        for(int i=1;i<=m;i++){
            dp[i][i]=0;
        }
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){

            ll kk;
            cin>>kk;
            for(int i=1;i<=kk;i++){
                cin>>a[i]>>t[i];
            }
            for(int i=1;i<=kk;i++){
                for(int j=i+1;j<=kk;j++){
                    dp[a[i]][a[j]]=dp[a[j]][a[i]]=min(dp[a[i]][a[j]],t[i]+t[j]);
                }
            }
        }

        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        while(q--){
            ll x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+dp[x][y]<<endl;
        }
    return 0;
}
