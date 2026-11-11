#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
using namespace std;
int c,n,m,d,q;
int k[505];
long long w[500005];
vector<long long>ljb[500005],ljb1[500005];
long long dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1ll<<60;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int t,t1;
            cin>>t>>t1;
            ljb[t].pb(i);
            ljb1[t].pb(t1);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<ljb[i].size();j++){
            for(int k=0;k<ljb[i].size();k++){
                int t1=ljb[i][j],t2=ljb[i][k];
                long long v=ljb1[i][j]+ljb1[i][k];
                dis[t1][t2]=dis[t2][t1]=min(dis[t1][t2],v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=1ll<<60;
        for(int i=0;i<ljb[x].size();i++){
            for(int j=0;j<ljb[y].size();j++){
                int t1=ljb[x][i],t2=ljb[y][j];
                ans=min(ans,dis[t1][t2]+ljb1[x][i]+ljb1[y][j]);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
