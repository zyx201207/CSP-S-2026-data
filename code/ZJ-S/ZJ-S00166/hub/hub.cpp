#include <bits/stdc++.h>
using namespace std;
int d[1000010],fa[21][1000010];
int res[1000010],used[1000010];
int lg[1000010],n,c,t,k;
vector<int> edge[1000010];
int ans=-1;
inline void init(int x,int f){
	fa[0][x]=f;
	d[x]=d[f]+1;
	for (int i=1;i<=lg[n];++i) fa[i][x]=fa[i-1][fa[i-1][x]];
	int size=edge[x].size();
	for (int i=0;i<size;++i){
		int v=edge[x][i];
		if (v==f) continue;
		init(v,x);
	}
}
inline int dist(int x,int y){
	if (d[x]>d[y]) swap(x,y);
	int p=x,q=y,lca=0;
	for (int i=lg[n];i>=0;--i){
		if (d[fa[i][q]]>=d[p]) q=fa[i][q];
	}
	
	if (x==y) lca=x;
	else{
		for (int i=lg[n];i>=0;--i){
			if (fa[i][p]!=fa[i][q]){
				p=fa[i][p];
				q=fa[i][q];
			}
		}
		lca=fa[0][p];
	}
	return d[x]+d[y]-d[lca]*2;
}
inline void dfs(int x,int f,int s,int cnt){
	if (s==k){
		int temp=0;
		for (int i=1;i<=k;++i){
			for (int j=1;j<=n;++j){
				if (!used[j]) temp=max(dist(res[i],j),temp);
			}
		}
		if (ans==-1) ans=temp;
		else ans=min(ans,temp);
		return;
	}
	int size=edge[x].size();
	for (int i=0;i<size;++i){
		int v=edge[x][i];
		if (v==f) continue;
		if (cnt==2){
			used[v]=1;
			res[s+1]=v;
			dfs(v,x,s+1,cnt);
			used[v]=0;
			res[s+1]=0;
		}
		else{
			dfs(v,x,s,cnt+1);
			used[v]=1;
			res[s+1]=v;
			dfs(v,x,s+1,cnt);
			used[v]=0;
			res[s+1]=0;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while (t--){
		memset(fa,0,sizeof(fa));
		cin>>n>>k;
		int a,b;
		for (int i=1;i<=n;++i){
			cin>>a>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for (int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
		init(1,0);
		dfs(1,0,0,0);
		cout<<ans<<'\n';
		for (int i=1;i<=n;++i){
			lg[i]=0;
			edge[i].clear();
			used[i]=0;
			res[i]=0;
		}
		ans=-1;
	}
}
