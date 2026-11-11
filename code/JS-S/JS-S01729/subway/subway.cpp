#include<bits/stdc++.h>
#define int long long
using namespace std;
int op,n,m,d,q;
const int N=510;
const int M=2e4+10;
int a[M][N],t[M][N];
int k[N];
bool vis[M][N];
int ne[M][N];
int pre[M][N];
int c[M];//out stop
int w[M];//change stop
int st,en,ans=0x3f3f3f3f;
void bfs(){
    deque<pair<int,pair<int,int> > > q;
    for(int i=1;i<=n;i++){
        int pr=pre[i][st],nx=ne[i][st];
        if(pr||nx){q.push_back({i,{st,0}});vis[i][st]=1;}
    }
    int ans=0x3f3f3f3f;
    while(q.size()){
        int id=q.front().first,u=q.front().second.first,dis=q.front().second.second;
        q.pop_front();
        if(u==en){
            ans=min(ans,dis);
            continue;
        }
        for(int i=1;i<=n;i++){
            int pr=pre[i][u],nx=ne[i][u];
            if(i==id){
                if(pr&&!vis[i][pr])q.push_front({i,{pr,dis}});
                if(nx&&!vis[i][nx])q.push_front({i,{nx,dis}});
                vis[i][pr]=vis[i][nx]=1;
            }
            else{
                if(pr&&!vis[i][pr])q.push_back({i,{pr,dis+1}});
                if(nx&&!vis[i][nx])q.push_back({i,{nx,dis+1}});
                vis[i][pr]=vis[i][nx]=1;
            }
        }
    }
    cout<<ans*t[1][1]<<"\n";
}
void solve(){
    cin>>st>>en;
    bfs();
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>op>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k[i];j++){
            if(j!=k[i])ne[i][a[i][j]]=a[i][j+1];
            else ne[i][a[i][j]]=0;
            if(j!=1)pre[i][a[i][j]]=a[i][j-1];
            else pre[i][a[i][j]]=0;
        }
    }
    while(q--)solve();
    return 0;
}
