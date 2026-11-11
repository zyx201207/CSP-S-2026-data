#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxm=2e4+100;
const ll INF=2e18+1;
ll c,n,m,d,q;
int a[511][maxm],t[510][maxm],ti[maxm][30],num[maxm][30],cnt[maxm];
ll w[maxm],k[maxm],dist[maxm][30];
ll idx,h[maxm],to[maxm],nxt[maxm],id[maxm];
void add(int u,int v,int kk) {
	to[++idx]=v;
	nxt[idx]=h[u];
	id[idx]=kk;
	h[u]=idx;
}
void dijkstra(int s,int lin,int tim) {
//	priority_queue<>
	priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>q;
	q.push({s,lin,tim});
	while(!q.empty()) {
		
		int u=q.top()[0],ide=q.top()[1];
		ll dis=q.top()[2];
//		if(ide==-1)puts("fhohofhoqwbdofi");
		q.pop();
		if(dis!=dist[u][ide])continue;
//		puts("in");
		for(int i=1;i<=cnt[u];i++){
			if(i==ide)continue;
			if(dis+ti[u][ide]+ti[u][i]<dist[u][i]){
//				cout<<u<<' '<<ide<<' '<<i<<' '<<ti[u][ide]+ti[u][i]<<'\n';
				dist[u][i]=dis+ti[u][ide]+ti[u][i];
				q.push({u,i,dist[u][i]});
			}
		}
		
//		cout<<"u "<<u<<' '<<ide<<'\n';
		for(int i=h[u];i;i=nxt[i]){
//			cout<<ide<<'\n';
			int v=to[i];
//			cout<<u<<' '<<v<<'\n';
			if(num[u][ide]!=id[i])continue;
			int newid=-1;
			for(int i=1;i<=cnt[v];i++){
				if(num[u][ide]==num[v][i]){
					newid=i;
					break;
				}
			}
			if(dis<dist[v][newid]){
//				cout<<u<<' '<<v<<' '<<ide<<'\n'; 			
				dist[v][newid]=dis;
				q.push({v,newid,dis});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	memset(nxt,-1,sizeof(nxt));
	cin>>c>>n>>m>>d>>q;	
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			ti[a[i][j]][++cnt[a[i][j]]]=t[i][j];
			num[a[i][j]][cnt[a[i][j]]]=i;
		}
		for(int j=1; j<k[i]; j++) {
//			cout<<a[i][j]<<' '<<a[i][j+1]<<'\n';
			add(a[i][j],a[i][j+1],i);
			add(a[i][j+1],a[i][j],i);
		}
	}
	while(q--){
		int x,y;
		ll ans=INF;
		cin>>x>>y;
//		cout<<x<<' '<<y<<'\n';
//		cout<<cnt[x]<<'\n';
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=m;j++)for(int k=1;k<=20;k++)dist[j][k]=INF;
			dist[x][i]=ti[x][i];
//			cout<<x<<' '<<num[x][i]<<"\n\n";
			dijkstra(x,i,ti[x][i]);
//			cout<<dist[123][1]<<' '<<dist[127][2]<<"fowafn\n";
		}		
		for(int i=1;i<=cnt[y];i++){
			if(ans>dist[y][i]+ti[y][i] ){
				ans=dist[y][i]+ti[y][i];
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
