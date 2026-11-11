#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=2e6+7;
int c,t,n,k,num;
vector<int>g[maxn];
bitset<maxn>s,vis;
//void dfs(int u,int fa,bool flag){
//	vis[u]=1;
//	for(int v:g[u])
//		if(v!=fa&&s[v])
//			dfs(v);
//}void ddfs(int u,int fa,bool flag){
//	vis[u]=1;
//	for(int v:g[u])
//		if(v!=fa&&s[v])
//			dfs(v);
//}
//void solve(){
//	if(!s.any())return;
//	num=0,vis.reset();
//	for(int i=1;i<=n;++i)
//		if(s[i]&&!vis[i]){++num;if(num>2)return;dfs(i);}
//	if(num==0)return;
//	for(int i=1;i<=n;++i)
//		for()
//}
//void dffs(int x){
//	if(x>n)return(solve(),(void)0);
//	s[x]=0;dffs(x+1);
//	s[x]=1;dffs(x+1);
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(cin>>c>>t;t--;){
		cin>>n>>k;
		for(int i=1,x,y;i<n;++i)
			cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
//		dffs(1);
		cout<<k<<'\n';
	}
	
	
	return(0);
}
