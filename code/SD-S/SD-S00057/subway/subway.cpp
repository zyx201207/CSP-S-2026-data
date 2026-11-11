#include<bits/stdc++.h>
using namespace std;
const int M=5e5+2,N=502;
int c,n,m,d,q,a[M]; 
struct node{
	int to,nxt,w;
}edge[M*2];
int head[M+N],idx=0;
void add(int frm,int to,int z){
	edge[++idx].nxt=head[frm];
	edge[idx].to=to;
	edge[idx].w=z;
	head[frm]=idx;
}
long long dis[N][20502];
long long dis2[3][M+N];
long long dis3[M+N];
void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s+m});
	dis[s][s+m]=0;
	while(!q.empty()){
		pair<int,int>pp =q.top();
		int u=pp.second;
		if(pp.first>dis[s][u])continue;
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[s][v]>dis[s][u]+edge[i].w){
				dis[s][v]=dis[s][u]+edge[i].w;
				q.push({dis[s][v],v});
			}
		}
	}
}
void dijkstra2(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s+m});
	dis2[s][s+m]=0;
	while(!q.empty()){
		pair<int,int>pp =q.top();
		int u=pp.second;
		if(pp.first>dis2[s][u])continue;
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis2[s][v]>dis2[s][u]+edge[i].w){
				dis2[s][v]=dis2[s][u]+edge[i].w;
				//cout<<s<<v<<dis2[s][v]<<" ";
				q.push({dis2[s][v],v});
			}
		}
	}
}
void dijkstra3(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	dis3[s]=0;
	while(!q.empty()){
		pair<int,int>pp =q.top();
		int u=pp.second;
		if(pp.first>dis3[u])continue;
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis3[v]>dis3[u]+edge[i].w){
				dis3[v]=dis3[u]+edge[i].w;
				q.push({dis3[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int k,u,v,w;
	for(int i=1;i<=n;i++){
		cin>>k;
		u=i+m;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
	}
	if(m<=20000){
		int x,y;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++){
			dijkstra(i);
	//		for(int j=1;j<=m;j++)cout<<dis[i][j]<<' ';
	//		cout<<endl;
		}
		//n+m个点 
		long long ans;
		for(int i=1;i<=q;i++){
			cin>>x>>y;
	//		memset(dis,0x7f,sizeof dis);
	//		dijkstra(x);
			ans=0x7f7f7f7f7f7f7f7f;
			for(int j=1;j<=n;j++){
				//cout<<dis[j][x]<<' '<<dis[j][y]<<' ';
				ans=min(ans,dis[j][x]+dis[j][y]);
			}
			cout<<ans+a[x]+a[y]<<"\n";
		}
	}
	else if(d==2){
		int x,y;
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			memset(dis3,0x3f,sizeof dis3);
			dijkstra3(x);
			cout<<dis3[y]+a[x]+a[y]<<"\n";
		}
	}
	else{
		int x,y;
		memset(dis2,0x3f,sizeof dis2);
		for(int i=1;i<=n;i++){
			dijkstra2(i);
		}
		//n+m个点 
		long long ans;
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			ans=0x7f7f7f7f7f7f7f7f;
			for(int j=1;j<=n;j++){
				ans=min(ans,dis2[j][x]+dis2[j][y]);
			}
			cout<<ans+a[x]+a[y]<<"\n";
		}
	}
	return 0;
} 
