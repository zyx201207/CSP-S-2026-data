#include<bits/stdc++.h>
#define ll long long
#define re register
#define pa pair
using namespace std;
const int N=5e5+5;
const ll INF=INT_MAX;
ll a[N],c,n,d,ans,dis,num,jj,fa[N][30],dep[N],vis[N],ne[N],k,di;
vector<int>G[N];
void dfs(int u,int f){
	fa[u][0]=f;dep[u]=dep[f]+1;
	for(re int j=1;j<=29;j++){
		fa[u][j]=fa[fa[u][j-1]][j-1];
	}
	for(auto v:G[u]){
		if(v==f)continue;
		dfs(v,u);
	} 
}
ll lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]!=dep[v])u=fa[u][0];
	if(u==v)return u;
	for(re int j=29;j>=0;j--){
		if(fa[u][j]!=fa[v][j]){
			u=fa[u][j],v=fa[v][j];
		}
	}
	return fa[u][0];
}
void dfs3(int u,int f,ll dep,int e){
	if(u==e){
		di=min(di,dep);
		return ;
	}
	for(auto v:G[u]){
		if(v==f)continue;
		dfs3(v,u,dep+1,e);
	} 
} 
ll dist(int u,int v){
	di=INF;
	dfs3(u,0,0,v);
	return di;
}

void dfs2(int u,int f){
	for(auto v:G[u]){
		if(v==f&&(!ne[v]))continue;
		vis[v]=1;
		dfs2(v,u);
	} 
}
ll solve(){
	vector<int>need;
	for(re int i=0;i<(1<<n);i++){
		need.clear();
		for(re int j=1;j<=n;j++){
			if(i&(1<<(j-1)))need.push_back(j);
		}
		if(need.size()!=k)continue;
		ll tot=0;
		for(auto j:need){
			vis[j]=0;
		}
		for(auto j:need){
			if(!vis[j]){
				vis[j]=1;
				dfs2(j,0);tot++;
			}
			//cout<<j<<' ';
		}//cout<<endl;
		if(tot>2){
			continue;//cout<<1<<endl;
		}
		ll cnt=0;
		for(re int j=1;j<=n;j++){
			ll res=INF;
			for(auto k:need){
				res=min(res,dist(j,k));
				//cout<<dist(j,k)<<endl;
			}
			cnt=max(res,cnt);
		}
		ans=min(ans,cnt);
		//cout<<cnt<<endl;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		ans=INF;
		cin>>n>>k;
		for(re int i=1;i<=n;i++){
			G[i].clear();
		}
		for(re int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		solve();
		cout<<ans<<endl;
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
6
1 2
2 3
1 4 
4 5
4 6
*/
