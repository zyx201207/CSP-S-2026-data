#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,fa[1000010],g[5010][5010],b[1000010],dis[5010][5010],ans;
bool a[1000010];
vector<int>e[1000010];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void dfs(int x,int cnt){
	if(cnt>k) return ;
	if(cnt+n-x+1<k) return ;
	if(x==n+1){
		if(cnt!=k) return ;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=n;i++){
			if(!a[i]) continue;
			for(int j=1;j<=n;j++){
				if(!a[j]) continue;
				if(g[i][j]) merge(i,j);
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!a[i]) continue;
			b[fa[i]]=1;
		} 
		for(int i=1;i<=n;i++) sum+=b[i];
		if(sum>2) return ;
		int d=0;
		for(int i=1;i<=n;i++){
			int dd=1e18;
			for(int j=1;j<=n;j++){
				if(!a[j]) continue;
				dd=min(dd,dis[i][j]);
			}
			d=max(d,dd);
		}
		ans=min(ans,d);
	}
	a[x]=1;
	dfs(x+1,cnt+1);
	a[x]=0;
	dfs(x+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e18;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			g[u][v]=1,dis[u][v]=1;
			g[v][u]=1,dis[v][u]=1;
		}
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
	return 0;
}
