#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int c,T,n,k,ans,a[N],b[N],fa[N],p[N],vis[N],dis[N],dep[N],ff[N][25],ll[N];
vector<int> mp[N];
bool o[1005][1005];
int get_fa(int x){
	return fa[x] == x ? x : fa[x]=get_fa(fa[x]);
}
void dfsp(int u,int pa){
	dep[u]=dep[pa]+1;
	ff[u][0]=pa;
	for(int i=1;i<=20;i++){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	for(int i=0;i<mp[u].size();i++){
		int v=mp[u][i];
		if(v==pa) continue;
		dfsp(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;i<=20;i++){
		if(d&1) u=ff[u][i];
		d>>=1;
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(ff[u][i]==ff[v][i]) continue;
		u=ff[u][i];
		v=ff[v][i];
	}
	return ff[u][0];
}
int w=0;
void dfs(int id){
	if(id==n+1){
		int res=0,tot=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				res++;
				b[++tot]=i;
			}
		}
		if(res!=k){
			return;
		}
		for(int i=1;i<=k;i++){
			fa[b[i]]=b[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				if(i==j) continue;
				if(o[b[i]][b[j]]==1){
					int x=get_fa(b[i]);
					int y=get_fa(b[j]);
					if(x!=y){
						fa[x]=y;
					}
				}
			}
		}
		for(int i=1;i<=k;i++) p[fa[b[i]]]=0;
		int kl=0;
		for(int i=1;i<=k;i++){
			if(p[fa[b[i]]]==0){
				p[fa[b[i]]]=1;
				kl++;
			}
		}
		for(int i=1;i<=k;i++){
			ll[b[i]]=1;
		}
		if(kl<=2){
			w++;
			//for(int i=1;i<=k;i++) cout<<b[i]<<' ';
			//cout<<endl;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(ll[i]==1) continue;
				int yy=LLONG_MAX;
				for(int j=1;j<=k;j++){
					yy=min(yy,dep[i]+dep[b[j]]-2*dep[lca(i,b[j])]);
				}
				cnt=max(cnt,yy);
			}
			//printf("%lld\n",cnt);
			ans=min(ans,cnt);
		}
		for(int i=1;i<=k;i++){
			ll[b[i]]=0;
		}
		return;
	}
	for(int i=0;i<=1;i++){
		a[id]=i;
		dfs(id+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=LLONG_MAX,w=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
			o[u][v]=1;
			o[v][u]=1;
		}
		dfsp(1,0);
		dfs(1);
		//cout<<w<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				o[i][j]=o[j][i]=0;
			}
			mp[i].clear();
		}
		printf("%lld\n",ans);
	}
	return ~(-1);
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