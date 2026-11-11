#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=520,M=5e5+5;
struct node {
	int d,s;
};
struct compare {
	bool operator()(const node & a,const node & b) {
		return a.s>b.s;
	}
};
int c,n,m,d,q;//n 条线路 m 个地铁站 d 条线路（MAX） q 条计划
int w[M],dis[N][N];
vector<node> e[M+N],r[M];
inline int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while('0'<=c&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x;
}
inline void add(int l,int r,int w) {
	e[l].push_back({r,w});
}
inline void uadd(int l,int r,int w) {
	add(l,r,w);
	add(r,l,w);
}
void Dijkstra(int st) { //Dijkstra 板子
	priority_queue<node,vector<node>,compare> q;
	dis[st][st]=0;
	q.push({m+st,0});
	while(!q.empty()) {
		node u=q.top();
		q.pop();
		if(u.s>dis[st][u.d-m]) continue;
		for(node v:e[u.d]) for(node z:e[v.d])
				if(dis[st][z.d-m]>u.s+v.s+z.s) {
					dis[st][z.d-m]=u.s+v.s+z.s;
					q.push({z.d,dis[st][z.d-m]});
				}
	}
}
signed main() {
	//freopen
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1; i<=m; i++)
		w[i]=read();
	for(int i=1,k,a,t; i<=n; i++) {
		k=read();
		while(k--) {
			a=read(),t=read();
			r[a].push_back({i,t});
			uadd(m+i,a,t);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=n; i++)
		Dijkstra(i);//跑线路之间的最短路
	int st,ed;
	while(q--) {
		st=read(),ed=read();
		int ans=1e17;
		for(node lz:r[st]) for(node rz:r[ed])//枚举并更新
				ans=min(ans,dis[lz.d][rz.d]+lz.s+rz.s);
		cout<<ans+w[st]+w[ed]<<"\n";
	}
	return 0;
}

