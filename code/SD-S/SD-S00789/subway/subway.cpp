//Created by Luogu User:951440
#include<bits/stdc++.h>
using namespace std;
long long dis[2000][2000];
long long w[2000],ans,T;
int c,n,m,d,q;
//void floyd() {
//	for(int k=1; k<=m+n; k++)
//		for(int i=1; i<=m+n; i++)
//			for(int j=1; j<=m+n; j++)
//				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	return ;
//}
struct node {
	int u;
	int v;
	long long w;
	bool operator<(const node &oth) const {
		return w>oth.w;
	}
};
vector<node> to[2000];
priority_queue<node> pq;
void dij(int st) {
	while(pq.size())
		pq.pop();
	for(node e:to[st])
		pq.push(e);
	while(pq.size()) {
		node e=pq.top();
		pq.pop();
		int now=e.u;
		int nxt=e.v;
		long long w=e.w;
		if(dis[st][nxt]<=dis[st][now]+w)
			continue;
		dis[st][nxt]=dis[st][now]+w;

		for(node e:to[nxt])
			if(e.v!=now)
				pq.push(node {nxt,e.v,e.w});
	}
	return ;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=n+m; i++) {
		for(int j=1; j<=n+m; j++)
			dis[i][j]=1000000000000000000;
		dis[i][i]=0;
	}
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		while(k--) {
			int x,t;
			cin>>x>>t;
			T=t;
			to[x].push_back(node {x,m+i,t});
			to[m+i].push_back(node {m+i,x,t});
//			dis[x][m+i]=t;
//			dis[m+i][x]=t;
		}
	}
	if(n+m>2000) {
		while(q--) {
			int x,y;
			cin>>x>>y;
			ans=w[x]+w[y]+T+T;
			cout<<ans<<'\n';
		}
		cout<<endl;
	}
	for(int i=1; i<=m; i++)
		dij(i);
//	floyd();
	while(q--) {
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y]+min(dis[x][y],dis[y][x]);
		cout<<ans<<'\n';
	}
	cout<<endl;
	return 0;
}
//dij我求你了，让我写对一次吧orz
