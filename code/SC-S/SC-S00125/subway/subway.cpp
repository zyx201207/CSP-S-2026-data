#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,D,q; // n 线路数 m 站数 d 最多有几线 q 计划数 
const int N=2000010;
vector<pair<int,int> > G[N];
int pcnt,a[N];
ll d[N];
bool vis[N];
ll Dijkstra(int st,int ed){
	fill(d,d+N+1,LLONG_MAX);
	memset(vis,false,sizeof(vis));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq; 
	d[st]=0;
	pq.push({0,st});
	while(!pq.empty()){
		pair<ll,int> cur=pq.top(); pq.pop();
		int u=cur.second; long long dnow=cur.first;
//		cout<<"in dijkstra: "<<u<<' '<<dnow<<endl;
		if(u==ed) return d[ed];
//		cout<<"!\n";
		if(vis[u]) continue;
		d[u]=dnow;
		vis[u]=true;
		for(pair<int,int> to:G[u]){
			int v=to.first,w=to.second;
//			cout<<"inin "<<v<<' '<<w<<'\n';
//			cout<<dnow<<' '<<w<<' '<<d[v]<<'\n';
			if(dnow+w<d[v]){
				d[v]=d[u]+w,pq.push({d[v],v});
//				cout<<"!!!"<<d[v]<<'\n';
			}
		}
	}
	if(d[ed]==LLONG_MAX) return -1;
	return d[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	pcnt=m+1;
	for(int i=1;i<=n;i++){
		int k,p=-1,w=-1; cin>>k;
		for(int j=1;j<=k;j++){
			cin>>p>>w;
			if(j!=1&&j!=k){
				G[pcnt].push_back({pcnt+1,0});	
				G[pcnt+1].push_back({pcnt,0});
				pcnt++;
				G[p].push_back({pcnt,w});	
				G[pcnt].push_back({p,w});
				pcnt++;
				G[p].push_back({pcnt,w});
				G[pcnt].push_back({p,w});
				G[pcnt-1].push_back({pcnt,0});
				G[pcnt].push_back({pcnt-1,0});		
			}
			else if(j==1){
				G[p].push_back({pcnt,w});	
				G[pcnt].push_back({p,w});
			}
			else if(j==k){
				G[pcnt].push_back({pcnt+1,0});
				G[pcnt+1].push_back({pcnt,0});
				pcnt++;
				G[p].push_back({pcnt,w});
				G[pcnt].push_back({p,w});
				pcnt++;
			}
		}
	}
//	for(int i=1;i<=pcnt;i++){
//		cout<<"i="<<i<<endl;
//		for(pair<int,int> it:G[i]){
//			cout<<it.first<<' '<<it.second<<'\n';
//		}
//		cout<<"\n\n\n";
//	}
	for(int i=1;i<=q;i++){
		int st,ed; cin>>st>>ed;
		cout<<Dijkstra(st,ed)+a[st]+a[ed]<<'\n';
//		for(int i=1;i<=m;i++) cout<<d[i]<<' ';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/