#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<int,ll>;
const int N=505;
const int M=5e5+10;

int c,n,m,d,q;
ll w[M],dist[N][N];
vector<P>sub[M];

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dist,0x3f3f3f,sizeof(dist));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a;
            ll t;
            cin>>a>>t;
            for(auto edge:sub[a]){
                int v=edge.first;
                ll w=edge.second;
                dist[i][v]=dist[v][i]=min(dist[v][i],t+w);
            }
            sub[a].push_back({i,t});
        }
    }
    for(int mid=1;mid<=n;mid++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i==mid||j==mid)continue;
                dist[j][i]=dist[i][j]=min(dist[i][j],dist[i][mid]+dist[mid][j]);
            }
        }
    }
    while(q--){
        int x,y;
        ll ans=4e18;
        cin>>x>>y;
        for(auto u:sub[x]){
            for(auto v:sub[y]){;
                ans=min(ans,u.second+v.second+dist[u.first][v.first]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
