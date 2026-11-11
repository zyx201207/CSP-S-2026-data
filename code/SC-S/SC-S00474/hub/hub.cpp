#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define MUBIAO ios_base::sync_with_stdio(0);
#define CESUO cin.tie(0);
#define frein freopen("hub.in","r",stdin);
#define freout freopen("hub.out","w",stdout);
#define mod 998244353
#define inf 1e14
#define pii pair<int,int>
using namespace std;
const int maxn=1e2+10;

/*
	不要慌张
	考虑二分答案
	二分 mid
	考虑如何判定
	我们肯定希望尽可能少放
	没有任何想法
	
	直接暴力 DP
	
	f_{i,j,k,0/1} 
	表示考虑 i 子树，当前子树内用了 j 个点，
	当前子树内的连通块离 i 最远 k 的子树内距离最小值，并且有了 1/2 个连通块
*/

int c,t,n,k,ans=inf,cnt=k; bool vis[maxn];

vector<int> edge[maxn];

struct DSU{
	int fa[maxn];
	void init(){for(int i=1;i<=n;i++)fa[i]=i;}
	int Find(int x){return (x!=fa[x])?(fa[x]=Find(fa[x])):(x);}
	void Merge(int x,int y){
		x=Find(x),y=Find(y);
		if(x==y)return;
		else fa[x]=y;
	}
}d;

void ToMerge(int x){
//	cout<<"Ting"<<endl;
	for(int v:edge[x])
		if(vis[v]&&v<x)
			d.Merge(x,v),cnt--;
//	cout<<"Tout"<<endl;
}

bool vv[maxn];

int Judge(){
	int res=0;
	queue<pii> q;
//	cout<<"ing"<<endl;
	for(int i=1;i<=n;i++)
		if(vis[i])q.push({i,0}),vv[i]=true;
		else vv[i]=false;
	while(q.size()){
		pii u=q.front(); q.pop(); res=max(res,u.second); 
		for(int v:edge[u.first])
			if(!vv[v])q.push({v,u.second+1}),vv[v]=true;
	}
//	cout<<"out"<<endl;
	return res;
}

void check(){
	d.init(),cnt=k;
	for(int i=1;i<=n;i++)
		if(vis[i])ToMerge(i);
	if(cnt<=2)
		ans=min(ans,max(1LL,Judge()));
}

void dfs(int dep,int siz){
//	cout<<"in :"<<dep<<" "<<siz<<endl;
	if(dep==n+1){if(siz==k)check(); return;}
	if(siz<k)
		vis[dep]=1,dfs(dep+1,siz+1);
	vis[dep]=0,dfs(dep+1,siz);
//	cout<<"out :"<<dep<<" "<<siz<<endl;
}

void Clear(){
	for(int i=1;i<=n;i++)edge[i].clear();
	ans=inf;
}

void Solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,
		edge[u].push_back(v),
		edge[v].push_back(u);
//	cout<<"SolveRead"<<endl;
	dfs(1,0);
	cout<<ans<<endl;
	Clear();
}

signed main(){
	MUBIAO CESUO
	frein freout
	cin>>c>>t;
	while(t--)Solve();
	return 0;
}