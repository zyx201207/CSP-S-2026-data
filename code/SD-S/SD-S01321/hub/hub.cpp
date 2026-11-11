#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
#define popcount(x) __builtin_popcountll(x)
#define pii pair<int,int>
#define fi first
#define se second
#define inf 1000000000
#define infll 1000000000000000000ll
#define lowbit(x) (x&-x)
using namespace std;
ll qpow(ll a,ll n){ll res=1;while(n){if(n&1)res=res*a;a=a*a;n>>=1;}return res;}
ll qpow(ll a,ll n,ll p){ll res=1;while(n){if(n&1){res=res*a%p;}a=a*a%p;n>>=1;}return res;}
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const int N=1e6+99;
int n,k;
vector<int>e[N];
pii E[N];
int fa[N];
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
bitset<N>vis;
int ans;
int dis[N];
int calc(){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<n;i++){
		int u=E[i].fi,v=E[i].se;
		if(vis[u]&&vis[v])merge(u,v);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i&&vis[i])cnt++;
	}
	
	if(cnt>2)return inf;
	queue<int>q;
	for(int i=1;i<=n;i++)dis[i]=0;
	for(int i=1;i<=n;i++){
		if(vis[i])q.push(i);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(!vis[v]&&!dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return *max_element(dis+1,dis+1+n);
}
void dfs(int x,int stp){
	if(stp==k){
		ans=min(ans,calc());
		return;
	}
	for(int i=x+1;i<=n;i++){
		vis[i]=true;
		dfs(i,stp+1);
		vis[i]=false;
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		E[i]={u,v};
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans=inf;
	dfs(0,0);
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fst;
	int c,T;
	cin>>c>>T;
	while(T--)solve();
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
