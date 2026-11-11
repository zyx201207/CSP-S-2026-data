#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ff first
#define ss second
int c,n,m,d,q;
int w[500010];
pair<int,int> v[500010][25];
int tot[500010];
long long dis[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    //cerr<<n<<" "<<m<<" "<<d<<" "<<q<<'\n';
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dis[i][j]=1e18;
        }
    } 
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            v[x][++tot[x]]={i,y};
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=tot[i];j++){
            for(int k=j+1;k<=tot[i];k++){
                dis[v[i][j].ff][v[i][k].ff]=min(dis[v[i][j].ff][v[i][k].ff],(long long)v[i][j].ss+v[i][k].ss);    
                dis[v[i][k].ff][v[i][j].ff]=min(dis[v[i][k].ff][v[i][j].ff],(long long)v[i][j].ss+v[i][k].ss);                    
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
    while(q--){
        int x,y;
        long long ans=1e18;
        cin>>x>>y;
        for(int i=1;i<=tot[x];i++){
            for(auto j=1;j<=tot[y];j++){
                ans=min(ans,dis[v[x][i].ff][v[y][j].ff]+w[x]+w[y]+v[x][i].ss+v[y][j].ss);
            }
        }
        cout<<ans<<'\n';
    }
}