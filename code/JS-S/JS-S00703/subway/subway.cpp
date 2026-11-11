#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mkpr make_pair
#define fi first
#define se second
using namespace std;
const int maxn=505,maxm=5e5+5;
const int Inf=(int)(1e18)+7;
int c,n,m,d,q;
int dis[maxn][maxn];
int wei[maxm];
int vc[maxm][21],wc[maxm][21];
int szv[maxm],szw[maxm];
int N=0;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>wei[i];
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:Inf);
    for(int i=1;i<=n;i++){
        int len=0;cin>>len;
        for(int j=1;j<=len;j++){
            int y,z;cin>>y>>z;vc[y][szv[y]++]=i;wc[y][szw[y]++]=z;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<szv[i];j++){
            for(int k=j+1;k<szv[i];k++){
                dis[vc[i][j]][vc[i][k]]=min(dis[vc[i][j]][vc[i][k]],wc[i][j]+wc[i][k]);
                dis[vc[i][k]][vc[i][j]]=min(dis[vc[i][k]][vc[i][j]],wc[i][j]+wc[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    while(q--){
        int x,y;cin>>x>>y;
        int ans=Inf;
        for(int i=0;i<szv[x];i++){
            for(int j=0;j<szv[y];j++){
                ans=min(ans,dis[vc[x][i]][vc[y][j]]+wc[x][i]+wc[y][j]);
            }
        }
        cout<<ans+wei[x]+wei[y]<<'\n';
    }
    return 0;
}