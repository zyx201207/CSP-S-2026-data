#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+5,M=5e2+5;
const int inf=1e9;
int Type,T,n,k;
vector<int> G[N];
int read(){
	int res=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res;
}
int vis[N],mark[N],f[N],res;
void dfs1(int x,int fa){
	mark[x]=1;
	for(int u:G[x]){
		if(vis[u]&&u!=fa) dfs1(u,x);
	}
}
int bfs(int x){
	queue<pair<int,int> > q;
	q.push({x,0});
	for(int i=1;i<=n;i++) f[i]=0;
	f[x]=1;
	while(!q.empty()){
		auto tmp=q.front();q.pop();
		int u=tmp.first,w=tmp.second;
		if(vis[u]) return w;
		for(int v:G[u]){
			if(f[v]) continue;
			f[v]=1;
			q.push({v,w+1});
		}
	}
	return 0;
}
void dfsk(int x){
	if(x==k){
		int cnt=0;
		for(int i=1;i<=n;i++) mark[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!mark[i]) cnt++,dfs1(i,0);
		}
		if(cnt>2) return ;
		int mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			mx=max(mx,bfs(i));
		}
//		for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
//		cout<<mx<<endl;
		res=min(res,mx);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfsk(x+1);
		vis[i]=0;
	}
}
void solve1(){
	res=inf;
	dfsk(0);
	printf("%d\n",res);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	Type=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			G[u].push_back(v),G[v].push_back(u);
		}
		solve1();
		for(int i=1;i<=n;i++) G[i].clear();
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
*/
