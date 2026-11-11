#include<bits/stdc++.h>
#define p pair<long long,int>
using namespace std;
const long long inf=1e16;
int c,n,m,d,q;
int w[500010];
int ki;
int now;
vector<pair<int,int>>g[1000010];
vector<int>g2[20010];
vector<int>tmp;
long long dis[1000010];
vector<int>a[20010];
//进行编号:1-m是站厅 
//后续是站台 
int dijkstra(int s,int t){
	priority_queue<p,vector<p>,greater<p>>pq;
	for(int i=1;i<=now;i++){
		dis[i]=inf;
	}
	dis[s]=0;
	pq.push({0LL,s});
	while(pq.size()){
		int u=pq.top().second;
		int w=pq.top().first;
		pq.pop();
		if(dis[u]<w) continue;
		for(auto j:g[u]){
			int v=j.first;
			int ww=j.second;
			if(dis[u]+ww<dis[v]){
				dis[v]=dis[u]+ww;
				pq.push({dis[v],v});
			}
		}
	}
	return dis[t];
}
int bfs(int s,int t){
	queue<int>que;
	for(int i=1;i<=m;i++) dis[i]=0;
	que.push(s);
	dis[s]=0;
	int cnt=0;
	while(que.size()){
		if(dis[t]) break;
		int h=que.front();
		que.pop();
		for(int j:g2[h]){
			if(dis[j]) continue;
			dis[j]=dis[h]+1;
			que.push(j);
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c>=12&&c<=19){
		now=0;
		int T;
		for(int i=1;i<=n;i++){
			tmp.clear();
			cin>>ki;
			for(int j=1;j<=ki;j++){
				int ai,ti;
				cin>>ai>>ti;
				T=ti;
				tmp.push_back(ai);
			}
			for(int j=0;j<ki;j++){
				for(int l=j+1;l<ki;l++){
					g2[tmp[j]].push_back(tmp[l]);
					g2[tmp[l]].push_back(tmp[j]);
				}
			}
		} 
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)*2*T+w[x]+w[y]<<"\n";
		}
	}else{
		now=m;
		for(int i=1;i<=n;i++){
			cin>>ki;
			for(int j=1;j<=ki;j++){
				int ai,ti;
				cin>>ai>>ti;
				now++;
				if(j!=1){
					g[now-1].push_back({now,0});
					g[now].push_back({now-1,0});
				}
				g[now].push_back({ai,ti});
				g[ai].push_back({now,ti});
			}
		} 
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";
		}
	}
}
