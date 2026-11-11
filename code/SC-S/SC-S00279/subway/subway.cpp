#include<bits/stdc++.h>
#define int long long
#define pii std::pair<int,int>
#define f(i,j,k) for(int i=j;i<=k;++i)
#define F(i,j,k) for(int i=j;i>=k;--i)
inline int read(){
	int x=0,type=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') type*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*type;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=5e5+10,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[maxn],dis[maxn+510],ans[maxn],u,v;
std::vector<int> a[510],t[510];
std::vector<pii> vec[maxn+510],qry[maxn];
std::priority_queue<pii,std::vector<pii>,std::greater<pii>> pq;
std::bitset<maxn+510> vis;
inline void dij(int S){
	f(i,1,n+m) dis[i]=inf,vis[i]=0;
	dis[S]=0; pq.push({0,S});
	while(!pq.empty()){
		auto p=pq.top(); pq.pop();
		if(vis[p.second]) continue;
		vis[p.second]=1;
		for(auto y:vec[p.second]) if(dis[y.first]>p.first+y.second) dis[y.first]=p.first+y.second,pq.push({dis[y.first],y.first});
	}
}
std::queue<int> Q;
inline void bfs(int S){
	f(i,1,n+m) dis[i]=-1,vis[i]=0;
	dis[S]=0; Q.push(S);
	while(!Q.empty()){
		auto p=Q.front(); Q.pop();
		for(auto y:vec[p]) if(dis[y.first]==-1) dis[y.first]=dis[p]+1,Q.push(y.first);
	}
}
inline void work(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read(); int type=-1;
	f(i,1,m) w[i]=read();
	f(i,1,n){
		int k=read(); a[i].resize(k+1); t[i].resize(k+1);
		f(j,1,k){
			a[i][j]=read(),t[i][j]=read(); 
			if(type==-1) type=t[i][j];
			else if(type!=t[i][j]) type=-2;
			vec[a[i][j]].emplace_back(m+i,t[i][j]);
			vec[m+i].emplace_back(a[i][j],t[i][j]);
		}
	}
	f(i,1,q) u=read(),v=read(),qry[std::min(u,v)].emplace_back(std::max(u,v),i);
	if(type!=-2){
		f(i,1,m) if(qry[i].size()){
			bfs(i);
			for(auto y:qry[i]) ans[y.second]=dis[y.first]*type+w[i]+w[y.first];
		}
	}
	else{
		f(i,1,m) if(qry[i].size()){
			dij(i);
			for(auto y:qry[i]) ans[y.second]=dis[y.first]+w[i]+w[y.first];
		}
	}
	f(i,1,q) write(ans[i]),putchar('\n');
}
signed main(){work();return 0;}