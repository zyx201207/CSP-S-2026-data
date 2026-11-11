#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+7;
int c,n,m,d,q,w[M],k[N];
vector<int>a[N],t[N];
int mp[2010][2010],dis[M+N],vis[M+N];
int head[N+M],nxt[(N+M)*2],to[(N+M)*2],val[(N+M)*2],tot;
inline void add(int x,int y,int z){
	nxt[++tot]=head[x];head[x]=tot;to[tot]=y;val[tot]=z;
}
inline void dij(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int> >qq;
	dis[s]=0;qq.push(make_pair(0,s));
	while(qq.size()){
		int x=qq.top().second;
		qq.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i],vv=val[i];
			if(dis[y]>dis[x]+vv){
				dis[y]=dis[x]+vv;
				qq.push(make_pair(-dis[y],y));
			}
		}
	}
}
inline void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			add(m+i,a[i][j-1],t[i][j-1]);
			add(a[i][j-1],m+i,t[i][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
		for(int j=1;j<=m;j++)mp[i][j]=dis[j];
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",w[x]+w[y]+mp[x][y]);
	}
}
inline void solve3(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			add(m+i,a[i][j-1],t[i][j-1]);
			add(a[i][j-1],m+i,t[i][j-1]);
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		dij(x);
		printf("%lld\n",w[x]+w[y]+dis[y]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1,x,y;j<=k[i];j++){
			scanf("%lld%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	if(c<=11)solve1();
	else solve3();
	return 0;
}