#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=110;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,k;
vector<int>g[N];
int dis[N][N];
int c,t;
bool vis[N];
bool vis2[N];
int ans=INF;
void dfs1(int u){
    vis2[u]=1;
    for(auto v:g[u]){
        if(vis2[v]) continue;
        if(vis[v]==0)   continue;
        dfs1(v);
    }
}
void check(){
    int res=0;
    int x;
    for(int i=1;i<=n;i++){
        vis2[i]=0;
        x=i;
        int cnt1=INF;
        for(int j=1;j<=n;j++){
            if(vis[j]==0)   continue;
            cnt1=min(cnt1,dis[i][j]);
        }
        res=max(res,cnt1);
    }
    if(ans<=res)    return;
    int cnt=1;
    dfs1(x);
    for(int i=1;i<=n;i++){
        if(vis[i]&&!vis2[i]){
            dfs1(i);
            cnt++;
        }
        if(cnt==3){
            return;
        }
    }
    ans=min(ans,res);
    return;
}
void dfs(int pos,int now){
    if(pos==n+1){
        if(now!=k)  return;
        check();
    }
    if(now>k)   return;
    if(now+(n-pos)+1<k) return;
    vis[pos]=1;
    dfs(pos+1,now+1);
    vis[pos]=0;
    dfs(pos+1,now);
}
void solve(){
    ans=INF;
    for(int i=1;i<=n;i++){
        g[i].clear();
        vis[i]=0;
        vis2[i]=0;
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INF;
        }
    }
	for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        dis[u][v]=1;
        dis[v][u]=1;
        dis[i][i]=0;
	}
	dis[n][n]=0;
	for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
	}
	dfs(1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>c;
	cin>>T;
	while(T--){
        solve();
	}
	return 0;
}
