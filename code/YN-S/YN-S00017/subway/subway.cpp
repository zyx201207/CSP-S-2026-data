#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=5e5+1000;
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int v,w;
};
vector<edge> T[N];
int f[N][31];//lca
ll dis[N];//lca
ll dep[N];//lca
ll add[N];
int tot;//总点数
struct sid{
	ll u,v,w;
};
bool cmp(sid s1,sid s2){
	return s1.w<s2.w;
}
ll cnt;//边数
sid s[N];
void dfs(int u,int pre){
	//cout<<"ASD";
	for(int i=0;i<T[u].size();i++){
		ll v=T[u][i].v,w=T[u][i].w;
		if(v==pre)continue;
	//	cout<<u<<","<<v<<","<<w<<"]\n";
		dep[v]=dep[u]+1;
	//	if(w<0)cout<<"qweqweqw";
		dis[v]=dis[u]+w;
		f[v][0]=u;
		dfs(v,u);
	}
	return;
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=23;i>=0;i--){
	//	cout<<dep[f[u][i]]<<" "<<fa[f[u][i]]<<"]";
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
		
	}
//	cout<<dep[v]<<"asdasd";
	if(u==v)return u;
	for(int i=23;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
ll cal(int u,int v){
	int ha=lca(u,v);
	//cout<<ha<<" ";
	 //if((dis[u]<dis[ha])||(dis[v]<dis[ha]))cout<<dep[u]<<","<<dep[v]<<","<<dep[ha]<<"\n";
	return (dis[u]-dis[ha])+(dis[v]-dis[ha]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//条数，点数
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>add[i];		
	}
	tot=m;//点数
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			tot++;
			cnt++;
			s[cnt].u=a;
			s[cnt].v=tot;
			s[cnt].w=t;
			if(j>=2){
				fa[tot]=find(fa[tot]);
				fa[tot-1]=find(fa[tot-1]);
				fa[tot]=fa[tot-1];
				T[tot].push_back({tot-1,0});
				T[tot-1].push_back({tot,0});
			}		
		}
	}
	sort(s+1,s+1+cnt,cmp);
	ll sum=m+n;
	ll cnt1=0;
	for(int i=1;i<=tot;i++){
		fa[i]=i;
	}
//	cout<<cnt<<"]]]]]]]]]]]\n";
//	for(int i=1;i<=cnt;i++){
//		cout<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<"\n";
//	}
	//cout<<"ASD";
	for(int i=1;i<=cnt;i++){
		ll u=s[i].u,v=s[i].v,w=s[i].w;
		ll x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=fa[y];
		cnt1++;
		//cout<<u<<"="<<v<<" "<<w<<"++\n";
		T[u].push_back({v,w});
		T[v].push_back({u,w});
		if(cnt1==sum-1)break;
	}
	dis[1]=0;
	dep[1]=1;
	dfs(1,0);	
	for(int j=1;j<=23;j++){
		for(int i=1;i<=tot;i++){	
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<cal(u,v)+add[u]+add[v]<<"\n";	
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/