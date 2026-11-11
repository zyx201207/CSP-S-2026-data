#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
//#define int long long
using namespace std;
const int N=2e5+5;
vector<int>G[N];
int dep[N];
int f[N][22];
int n,k;
bool flag[N];
bool vis[N];
void dfs(int u,int fa){
    f[u][0]=fa;
    for(int j=1;j<=20;j++){
        f[u][j]=f[f[u][j-1]][j-1];
    }
    for(int v:G[u]){
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(x==y)return x;
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--){
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
    }
    if(x==y)return x;
    for(int i=20;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int cal(int x,int y){
    return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int scc(int u,int fa){
    for(int v:G[u]){
        if(v==fa)continue;
        if(!flag[v])continue;
        vis[v]=1;
        scc(v,u);
    }
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++){
        if(flag[i]&&!vis[i]){
            vis[i]=1;
            scc(i,i);
            cnt++;
        }
        if(cnt>2)return 0;
    }
    return 1;
}
int ans=1e9;
void work_out(){
    int ma=0;
    for(int i=1;i<=n;i++){
        int mi=1e9;
        if(flag[i]==1){
        	mi=0;
		}
        for(int j=1;j<=n;j++){
            if(!flag[j])continue;
            mi=min(mi,cal(i,j));
        }
        ma=max(ma,mi);
    }
    ans=min(ans,ma);
}
void dfs2(int i,int cnt){
    if(cnt>k)return;
    if(i>n){
        if(cnt<k)return;
        if(check()){
            work_out();
        }
        return;
    }
    flag[i]=1;
    dfs2(i+1,cnt+1);
    flag[i]=0;
    dfs2(i+1,cnt);
}
void init(){
    for(int i=1;i<=n;i++){
        dep[i]=0;
        G[i].clear();
        for(int j=1;j<=20;j++){
            f[i][j]=0;
        }
    }
    ans=1e9;
}
void solve(){
    cin>>n>>k;
    init();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    dfs2(1,0);
    cout<<ans<<endl;
}
signed main(void){
	IOS;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
	return 0;
}
