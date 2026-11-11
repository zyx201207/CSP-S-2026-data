#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}namespace ZXY{
	const int N=50;
	int c,t,n,k;int ans=2e9;
	vector<int>g[N];int F[N];
	int f[N][20],dep[N];
	vector<int>now;int pre[N];
	struct Edge{int u,v;}e[N];
	bool key[N];int d[N];
	int find(int x){
		return F[x]==x?x:F[x]=find(F[x]);
	}int LCA(int u,int v){
		if(dep[u]<dep[v])swap(u,v);
		while(dep[pre[u]]>=dep[v])u=pre[u];
		if(u==v)return u;
		while(pre[u]!=pre[v])u=pre[u],v=pre[v];
		return pre[u];
	}void getans(){
		rmp(v,now)key[v]=1;
		iota(F+1,F+n+1,1);
		int cnt=0;
		rep(1,n-1,i)
			if(key[e[i].u]&&key[e[i].v])
				F[find(e[i].u)]=find(e[i].v);
		rmp(v,now)if(find(v)==v)cnt++;
		if(cnt>2){
			rmp(v,now)key[v]=0;
			return;
		}fill(d+1,d+n+1,2e9);
		rep(1,n,i){
			if(key[i])d[i]=0;
			else{
				rmp(v,now)
					d[i]=min(d[i],dep[i]+
					dep[v]-2*dep[LCA(i,v)]);
			}
		}int res=0;
		rep(1,n,i)res=max(res,d[i]);
		ans=min(ans,res);
		rmp(v,now)key[v]=0;
	}void dfs2(int i,int sum){
		if(i>n){
			if(sum!=k)return;
			getans();
			return;
		}dfs2(i+1,sum);
		now.push_back(i);
		dfs2(i+1,sum+1);
		now.pop_back();
	}void dfs(int u,int fa){
		f[u][0]=fa;dep[u]=dep[fa]+1;
		pre[u]=fa;
		rmp(v,g[u]){
			if(v==fa)continue;
			dfs(v,u);
		}
	}void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>c>>t;
		while(t--){
			cin>>n>>k;
			ans=2e9;now.clear();
			rep(1,n,i)g[i].clear();
			rep(1,n,i) rep(0,19,j)f[i][j]=0;
			rep(1,n-1,i){
				int u,v;cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
				e[i]={u,v};
			}dfs(1,0);
			for(int j=1;(1<<j)<=n;j++)
				rep(1,n,i)f[i][j]=f[f[i][j-1]][j-1];
			dfs2(1,0);
			cout<<ans<<'\n';
		}
	}
}
int main(){fre();ZXY::solve();}
