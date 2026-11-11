#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE "hub"
#define JUDGE
const int N=30;
int pt[N];
int n,k,ans=n;
int hsh[N],dis[N];
vector<int> g[N];
void markpt(int u){
	for(auto v:g[u])
		if(hsh[v])
			hsh[v]=0,markpt(v);
}
int bfs(int s){
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	dis[s]=0,q.push(s);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:g[u])
			if(dis[v]>dis[u]+1)
				dis[v]=dis[u]+1,q.push(v);
	}
	int mndis=n;
	for(int i=1; i<=k; i++) mndis=min(dis[pt[i]],mndis);
//	for(int i=1; i<=n; i++){
//		cout<<mndis<<' ';
//	}
//	cout<<'\n';
	return mndis;
}
void solve(){
	for(int i=1; i<=k; i++)
		hsh[pt[i]]=1;
	int cnt=0;
	for(int i=1; i<=k; i++)
		if(hsh[pt[i]])
			cnt++,markpt(pt[i]);
	if(cnt>2) return ;
	int mx=0;
//	for(int i=1; i<=k; i++){
//		cout<<pt[i]<<' ';
//	}
	for(int i=1; i<=n; i++){
		mx=max(mx,bfs(i));
	}
//	cout<<mx<<'\n';
	ans=min(mx,ans);
}
void dfs(int m,int lst){
	if(m>k){
		solve(); return ;
	}
	for(int i=lst+1; i<=n; i++)
		pt[m]=i,dfs(m+1,i);
}

signed main(){
	#ifdef JUDGE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
	#endif
	int t,c,u,v;
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1; i<n; i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
		for(int i=1; i<=n; i++){
			g[i].clear();
		}
	}
	#ifdef JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
/*
in last 5min
niceeeeeeeee
骗到15分 
*/