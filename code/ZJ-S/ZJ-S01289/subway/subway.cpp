#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,d;
	bool operator<(const node &b)const{
		return d>b.d;
	}
};
struct edge{
	int to,nxt,val;
}e[5000010];
int c,n,m,d,qq,sum,a,cnt,head[5000010],aa[500010],bb[500010],vis[5000010],dis[5000010];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].val=w;
	head[u]=cnt;
}
void dijkstra(int x){
	priority_queue<node>q;
	int N;
	if(c>=12&&c<=15) N=200000;
	else N=1000000;
	for(int i=1;i<=N;i++) dis[i]=1e18;
	for(int i=1;i<=N;i++) vis[i]=0;
	q.push({x,0});
	dis[x]=0;
	while(!q.empty()){
		int u=q.top().u,d=q.top().d;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>a;
		add(i,i+m,a);
		add(i+m,i,a);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		sum+=k;
		for(int j=1;j<=k;j++){
			cin>>aa[j]>>bb[j];
			add(i*m+m+aa[j],aa[j]+m,bb[j]);
			add(aa[j]+m,i*m+m+aa[j],bb[j]);
		}
		for(int j=1;j<k;j++){
			add(i*m+m+aa[j],i*m+m+aa[j+1],0);
			add(i*m+m+aa[j+1],i*m+m+aa[j],0);
		}
	}
	while(qq--){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
}
