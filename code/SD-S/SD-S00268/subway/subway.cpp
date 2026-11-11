#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
int c,n,m,d1,q1,k,cnt,x,y,dot[500050],trans[500050];
int w[500050],dis[305][305],pre[305],d[305],f[305],from[305];
bool vis[305];
typedef pair<int,int> pr;
priority_queue<pr,vector<pr>,greater<pr> > q;
struct node {
	int to,next,num,len;
} a[1000010];
inline void add(int u,int v,int num,int trans) {
	a[++k]= {v,pre[u],num,trans};
	pre[u]=k;
}
void dijistra(int x,int y) {
	while(!q.empty())
		q.pop();
	memset(d,0x3f,sizeof d);
	memset(f,0,sizeof f);
	memset(vis,0,sizeof vis);
	q.push({w[x],x});
	d[x]=w[x];
	while(!q.empty()) {
		pr p=q.top();
		q.pop();
		int di=p.first,na=p.second;
		if(vis[na])
			continue;
		if(dis[x][na]>d[na]+w[na]){
			dis[x][na]=d[na]+w[na]+a[from[na]].len;
		}
		vis[na]=true;
		for(int i=pre[na]; i; i=a[i].next) {
			d[na]+=a[i].len;
			int to=a[i].to;
			if((f[to]==f[na]||f[to]==0)&&(a[i].num==f[na]||na==x)) {
				if(d[to]>d[na]) {
					d[to]=min(d[to],d[na]);
					f[to]=f[na];
					q.push({d[to],to});
					from[to]=i;
				}
			} else {
				if(d[na]+a[na].len<d[to]) {
					d[to]=min(d[to],d[na]+a[na].len);
					q.push({d[to],to});
					from[to]=i;
				}
			}
			d[na]-=a[i].len;
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d1>>q1;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>x;
		cnt++;
		for(int j=1; j<=x; j++) {
			cin>>dot[j]>>trans[j];
			if(j>=2) {
				add(dot[j-1],dot[j],cnt,trans[j-1]);
				add(dot[j],dot[j-1],cnt,trans[j]);
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=n; i++)
		dis[i][i]=0;
	for(int i=1; i<=q1; i++) {
		cin>>x>>y;
		if(dis[x][y]<=1e9) {
			cout<<dis[x][y];
			continue;
		}
		dijistra(x,y);
		cout<<dis[x][y]<<"\n";
	}
	return 0;
}
