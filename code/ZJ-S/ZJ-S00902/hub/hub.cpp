#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define pii pair<int,int>
#define fir first
#define sec second
const int inf=1e18; 
inline int read(){
	int w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return w*f;
} 
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0'); 
}
const int N=1e6+7;
int tid,T;
int n,m,ans;
vector<int> e[N];
struct Edge{
	int u,v;
}E[N];
unordered_map<int,int> mp[N];
bool vis[N];
int a[N];
int fa[N][21],dep[N];
void dfs1(int u,int f){
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs1(v,u);
	} 
}
inline int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	per(k,20,0){
		if(dep[fa[u][k]]>=dep[v]) u=fa[u][k];
	} 
	if(u==v) return u;
	per(k,20,0){
		if(fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	}
	return fa[u][0];
}
inline int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)]; 
} 
struct DSU{
	int fa[N];
	void init(){
		rep(i,1,n) fa[i]=i;
	}
	int find(int u){
		return (fa[u]==u)?u:fa[u]=find(fa[u]);
	}
	void merge(int u,int v){
		u=find(u),v=find(v);
		fa[v]=u;
	}
	bool is(int u,int v){
		return find(u)==find(v);
	}
}dsu;
void cal(){
	int cnt=0;
	dsu.init();
	rep(i,1,m){
		rep(j,i+1,m){
			if(mp[a[i]].count(a[j])||mp[a[j]].count(a[i])){
				if(dsu.is(a[i],a[j])) continue;
				dsu.merge(a[i],a[j]);
				cnt++;
			}
		}
	}
//	cout<<mp[2].count(9)<<"\n";
//	cout<<"cnt="<<cnt<<"\n"; 
	if(cnt>=m-2){
//		rep(i,1,m){
//			cout<<a[i]<<" ";
//		}
//		cout<<"\n";
		int res=0;
		rep(i,1,n){
			int tmp=inf; 
			rep(j,1,m){
				tmp=min(tmp,dis(i,a[j])); 
			}
			res=max(res,tmp);
//			cout<<"tmp="<<tmp<<"\n";
		}
		ans=min(ans,res);
	}
}
void dfs(int step){
	if(step==m+1){
		cal();
		return;
	} 
	rep(i,1,n){
		if(!vis[i]){
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
void solve(){
	n=read(),m=read();
//	cerr<<"n="<<n<<" m="<<m<<"\n";
	ans=inf;
	rep(i,1,n) mp[i].clear();
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1){
		int u=read(),v=read();
		E[i]={u,v};
		mp[u][v]=1;
		mp[v][u]=1;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	rep(j,1,20){
		rep(i,1,n){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
//	cout<<LCA(1,5)<<"\n";
//	cout<<dis(2,4)<<"\n";
	dfs(1);
	cout<<ans<<"\n";
}
/*
0 1
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
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	tid=read(),T=read();
	while(T--){
		solve();
	}
	return 0;
}
