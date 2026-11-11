#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,r,k;
struct QvQ{
	int a,t;
};
struct Q{
	int u,v,id;
}q[500100];
int a[500100];
vector<QvQ>b[500100];

vector<int>e[500100];
vector<int>w[500100];
int dis[100010],vis[100010],ans[500100];
struct De{
	int id,d;
};
bool operator < (De a,De b){
	return a.d>b.d;
}
bool cmp(Q a,Q b){
	return a.u>b.u;
}
priority_queue<De>qe;

void Dijkstra(int u){
	for(int i=1;i<=m;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[u]=0;
	qe.push(De{u,0});
	while(!qe.empty()){
		int x=qe.top().id;
		qe.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(int i=0;i<e[x].size();i++){
			if(dis[e[x][i]]>dis[x]+w[x][i]){
				dis[e[x][i]]=dis[x]+w[x][i];
				qe.push(De{e[x][i],dis[e[x][i]]});
			}
		}
	}
}

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int x,y;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			b[i].push_back(QvQ{x,y});
		}
	}
	for(int i=1;i<=r;i++){
		int x,y;
		cin>>x>>y;
		q[i].u=x;
		q[i].v=y;
		q[i].id=i;
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			e[b[i][0].a].push_back(b[i][1].a);
			e[b[i][1].a].push_back(b[i][0].a);
			w[b[i][0].a].push_back(b[i][0].t+b[i][1].t);
			w[b[i][1].a].push_back(b[i][0].t+b[i][1].t);
		}
		sort(q+1,q+r+1,cmp);
		int op=0;
		for(int i=1;i<=r;i++){
			if(q[i].u!=op){
				op=q[i].u;
				Dijkstra(op);
			}
			ans[q[i].id]=dis[q[i].v]+a[q[i].u]+a[q[i].v];
		}
		for(int i=1;i<=r;i++){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}
