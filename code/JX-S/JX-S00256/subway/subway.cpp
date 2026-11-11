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
void dfs1(int u){
    vis2[u]=1;
    for(auto v:g[u]){
        if(vis2[v]) continue;
        dfs1(v);
    }
}
void check(){
    int res=INF;
    int x;
    for(int i=1;i<=n;i++){
        vis2[i]=0;
        if(vis[i]==0)   continue;
        x=i;
        for(int j=i;j<=n;j++){
            if(vis[j]==0)   continue;
            res=min(res,dis[i][j]);
        }
    }
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
    for(int i=1;i<=n;i++){
        g[i].clear();
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
	//for(int i=1;i<=n;i++){
      //  for(int j=1;j<=n;j++){
        //    cout<<dis[i][j]<<' ';
       // }
        //cout<<'\n';
	//}
	dfs(1,0);
	cout<<ans;
}
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>c>>t;
	cin>>T;
	while(T--){
        solve();
	}
	return 0;
}
