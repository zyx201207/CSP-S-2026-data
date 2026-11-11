#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define is insert
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=1e6+5;
const int INF=1e18;
int O,T,n,k,dep[N],fa[N],ans,dis[25][25];
vector<int>e[N];
pii mx;
inline int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
inline bool check(int x){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	vector<int>tmp;
	unordered_set<int>us;
	for(int i=0;i<n;i++){
		if(x&(1<<i)){
			tmp.eb(i+1);
			us.is(i+1);
		}
	}
	for(int i:tmp){
		for(int j:e[i]){
			if(us.find(j)!=us.end()){
				int fi=find(i);
				int fj=find(j);
				if(fi==fj)continue;
				fa[fi]=fj;
			}
		}
	}
	unordered_set<int>tt;
	for(int i:tmp){
		tt.is(find(i));
	}
	return (tt.size()<=2);
}
inline void solve1(){
	cin>>n>>k;
	ans=INF;
	for(int i=1;i<=n;i++){
		e[i].clear();
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=INF;
		}
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].eb(v);
		e[v].eb(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		if(!check(i))continue;
		int res=0;
		unordered_set<int>us;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				us.is(j+1);
			}
		}
		for(int j=1;j<=n;j++){
			if(us.find(j)==us.end()){
				int h=INF;
				for(int l:us){
					h=min(h,dis[j][l]);
				}
				res=max(res,h);
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
inline void dfs(int u,int la){
	dep[u]=dep[la]+1;
	mx=max(mx,make_pair(dep[u],u));
	for(int v:e[u]){
		if(v==la)continue;
		dfs(v,u);
	}
}
inline void solve2(){
	cin>>n>>k;
	ans=INF;
	if(n<=20){
		for(int i=1;i<=n;i++){
			e[i].clear();
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				dis[i][j]=INF;
			}
		}
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].eb(v);
			e[v].eb(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k)continue;
			if(!check(i))continue;
			int res=0;
			unordered_set<int>us;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					us.is(j+1);
				}
			}
			for(int j=1;j<=n;j++){
				if(us.find(j)==us.end()){
					int h=INF;
					for(int l:us){
						h=min(h,dis[j][l]);
					}
					res=max(res,h);
				}
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	else{
		mx={0,0};
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].eb(v);
			e[v].eb(u);
		}
		dfs(1,0);
		int rt=mx.sec;
		mx={0,0};
		dfs(rt,0);
		if(k==n){
			cout<<1<<'\n';
		}
		else if(k>=mx.fir-2){
			cout<<1<<'\n';
		}
		else{
			cout<<min((mx.fir+1-k)/2,(mx.fir+2-k)/3)<<'\n';
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>O>>T;
	if(O<=3){
		while(T--){
			solve1();
		}
	}
	else{
		while(T--){
			solve2();
		}
	}
}
/*
17:53 15pts
*/