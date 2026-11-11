#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,dis[505][505],w[500005];
vector<pair<ll,ll> > a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        ll siz;
        cin>>siz;
        for(int j=1;j<=siz;j++){
            ll x,y;
            cin>>x>>y;
            a[x].push_back({i,y});
        }
    }
   // return 0;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<int(a[i].size());j++){
            for(int k=0;k<int(a[i].size());k++){
                if(j==k) continue;
                ll x=a[i][j].first,y=a[i][k].first,val=a[i][j].second+a[i][k].second;
                dis[x][y]=min(dis[x][y],val);
                dis[y][x]=min(dis[y][x],val);
            }
        }
    }
    //cout<<dis[1][2];
   // return 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    //return 0;
    for(int i=1;i<=q;i++){
        ll x,y,ans=1e18;
        cin>>x>>y;
        for(int j=0;j<int(a[x].size());j++){
            for(int k=0;k<int(a[y].size());k++){
                ll v1=a[x][j].first,v2=a[y][k].first,val=a[x][j].second+a[y][k].second+w[x]+w[y];
               // cout<<v1<<" "<<v2<<" "<<val<<"\n";
                ans=min(ans,dis[v1][v2]+val);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
