#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> PII;
const int M=5e5+10,N=510;
long long x,y,w[M],k[N];
long long c,n,m,d,q;
vector<PII> t[N];
vector<PII> g[M];
long long dij(){
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,x});
	vector<long long> dis(m+5);
	vector<bool> book(m+5);
	for(int i=1;i<=m;i++){
		dis[i]=1e18;
	}
	dis[x]=0;
	while(!heap.empty()){
		int u=heap.top().second;
		heap.pop();
		if(!book[u]){
			book[u]=1;
		}
		else continue;
		for(int i=0;i<g[u].size();i++){
			int r=g[u][i].first;
			if(dis[u]+g[u][i].second<dis[r]){
				dis[r]=dis[u]+g[u][i].second;
				heap.push({dis[r],r});
			}
		}
	}
	return dis[y];
}
long long bfs(){
	vector<long long> dis(m+5);
	vector<bool> book(m+5);
	queue<int> q;
	q.push(x);
	book[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int r=g[u][i].first;
			if(book[r]==1) continue;
			book[r]=1;
			dis[r]=dis[u]+g[u][i].second;
			if(r==y) return dis[r];
			q.push(r);
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		t[i].push_back({0,0});
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			t[i].push_back({a,b});
		}
	}
	if(c>=12 && c<=19){
		for(int i=1;i<=n;i++){
			for(int j=1;j<k[i];j++){
				for(int l=j+1;l<=k[i];l++){
					g[t[i][j].first].push_back({t[i][l].first,t[i][j].second+t[i][l].second});
					g[t[i][l].first].push_back({t[i][j].first,t[i][j].second+t[i][l].second});
				}
			}
		}
		while(q--){
			cin>>x>>y;
			cout<<w[x]+bfs()+w[y]<<"\n";
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<k[i];j++){
				for(int l=j+1;l<=k[i];l++){
					g[t[i][j].first].push_back({t[i][l].first,t[i][j].second+t[i][l].second});
					g[t[i][l].first].push_back({t[i][j].first,t[i][j].second+t[i][l].second});
				}
			}
		}
		while(q--){
			cin>>x>>y;
			cout<<w[x]+dij()+w[y]<<"\n";
		}
		return 0;
	}
	return 0;
}
