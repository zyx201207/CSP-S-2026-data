#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int T,n,d[N],fa[N],ans;
bool f[N],vis[N];
vector<int> e[N];
void dfs(int u,int fr){
	for(auto v:e[u]){
		if(v==fr||vis[v]||!f[v])continue;
		vis[u]=1;
		dfs(v,u);
	}
}
void dfs2(int u){
	d[u]=d[fa[u]]+1;
	for(auto v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dfs2(v);
	}
}
int Lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	while(1){
		if(d[u]==d[v]) break;
		u=fa[u];
	}
	if(u==v) return u;
	while(1){
		if(u==v)break;
		u=fa[u],v=fa[v];
	}
	return u;
}
void check(){
	for(int i=1;i<=n;++i) vis[i]=0;
	int sum=0;
	for(int i=1;i<=n;++i)if(!vis[i]&&f[i])dfs(i,0),sum++;
	if(sum>2) return;
	int xxx=0;
	for(int i=1;i<=n;++i){
		if(f[i]) continue;
		int sum=1e9;
		for(int j=1;j<=n;++j){
			if(f[j]){
				sum=min(sum,d[i]+d[j]-2*d[Lca(i,j)]);
			}
		}
		xxx=max(xxx,sum);
	}
	ans=min(ans,xxx);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T>>T;
	while(T--){
		int k=0;
		cin>>n>>k;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n>20){
			cout<<(n-1)/2<<"\n";
			continue;
		}
		ans=n-1;
		dfs2(1);
		for(int s=0;s<(1<<n);++s){
			for(int i=1;i<=n;++i) f[i]=0;
			int sum=0;
			for(int i=1;i<=n;++i) if((s&(1<<(i-1))))sum++,f[i]=1;
			if(sum!=k) continue;
			check();
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i) e[i].clear();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
