#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,k,f[N][N],fa[N];
vector<int> g[N];
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			f[i][i]=0,fa[i]=i;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			f[u][v]=f[v][u]=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);		
		int ans=0x7fffffff;
		for(int S=1;S<(1<<n);S++){
			int res=0;
			vector<int> hub; bitset<N> inh;
			for(int i=1;i<=n;i++)
				if(S&(1<<(i-1))) {
					hub.push_back(i);
					inh[i]=1;
				}
			if(inh.count()!=k) continue;
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int u:hub) for(int v:g[u])
				if(inh[v]) fa[Find(u)]=Find(v);
			set<int> ltk;
			for(int u:hub)
				ltk.insert(fa[u]);
			if(ltk.size()>2) continue;
			for(int i=1;i<=n;i++){
				if(inh[i]) continue;
				int di=0x7fffffff;
				for(int v:hub)
					di=min(di,f[i][v]);
				res=max(res,di);
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			g[i].resize(0);
	}
	return 0;
} 
