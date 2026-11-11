#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fs first
#define sd second
using namespace std;
const int N=500005,M=505;
int c,n,m,d,q;
int w[N];
vector<PII> G[N+M];
int dis[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            G[i].push_back({a+n,t});
            G[a+n].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<G[i+n].size();j++){
            for(int k=j+1;k<G[i+n].size();k++){
                dis[G[i+n][j].fs][G[i+n][k].fs]=dis[G[i+n][k].fs][G[i+n][j].fs]=min(dis[G[i+n][k].fs][G[i+n][j].fs],G[i+n][k].sd+G[i+n][j].sd);
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
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=LLONG_MAX;
        for(int i=0;i<G[x+n].size();i++){
            for(int j=0;j<G[y+n].size();j++){
                ans=min(ans,G[x+n][i].sd+G[y+n][j].sd+dis[G[x+n][i].fs][G[y+n][j].fs]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}