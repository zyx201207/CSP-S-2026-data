#include <bits/stdc++.h>

using namespace std;
const int N=1e6+10;
int c,t,n,k;
int col[N];
vector<vector<int> > ans;
vector<int> now;
int vis[N];
vector<int> g[N];
void dfs(int pos,int nk){
	if(nk==n&&pos<=k) return ;
	if(pos==k+1){
		ans.push_back(now);
		return ;
	}
	if(n-nk+pos-1<k) return ;
	for(int i=nk+1;i<=n+pos-k;++i){
		if(vis[i]) continue;
		vis[i]=1;
		now.push_back(i);
		dfs(pos+1,i);
		vis[i]=0;
		now.pop_back();
	}
}
int f[N][21],dep[N];
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];++i)
		f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs1(v,u);
	}
}
bool check(vector<int> v){
	for(int i=1;i<=n;++i) col[i]=0;
	int cnt=0;
	for(auto u:v){
		bool flag=0;
		for(auto son:g[u])
			flag|=col[son];
		if(!flag) cnt++;
		col[u]=1;
	}
	return (cnt<=2);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;--i)
		if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;--i)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return f[u][0];
}
int get(int u,int v){
	int L=lca(u,v);
	return dep[u]+dep[v]-2*dep[L];
}
void solve(){
	ans.clear();
	for(int i=1;i<=n;++i){
		dep[i]=0;
		g[i].clear();
		for(int j=0;j<=20;++j)
			f[i][j]=0;
	}
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs1(1,0);
	int fin=1e9;
//	cout<<"lca "<<lca(1,5)<<'\n';
//	cout<<"get "<<get(1,5)<<'\n';
	for(auto tmp:ans){
		if(check(tmp)){
//			cout<<"tiaoshi ";
//			for(auto v:tmp)
//				cout<<v<<' ';
//			cout<<'\n';
			int cur=0;
			for(int i=1;i<=n;++i){
				int res=1e9;
				for(auto v:tmp){
					if(i==v){
						res=0;
						break;
					}
					res=min(res,get(i,v));
				}
				cur=max(cur,res);
			}
			fin=min(fin,cur);
		}
	}
	cout<<fin<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int _=1;_<=t;++_){
		if(c<=3||c==7){
			solve();
		}
	}
	return 0;
}
