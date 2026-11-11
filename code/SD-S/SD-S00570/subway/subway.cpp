#include<bits/stdc++.h>
using namespace std;
#define int long long
bool AA;
int c,n,m,d,q,w[500005],k,a,tt,x,y,st[500550],dis[500550],ddis[1005][1005];
#define pii pair<int,int>
vector<pii>ve[500550];
vector<int>ve2[500550];
__inline void Dijkstra(int x){
	for(int i=0;i<=n+m+2;i++){
		st[i]=0;
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push({0,x});
	dis[x]=0;
	while(!pq.empty()){
		pii t=pq.top();
		pq.pop();
		int u=t.second;
		if(st[u]) continue;
		st[u]=1;
		for(auto i:ve[u]){
			int v=i.first,ww=i.second;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				pq.push({dis[v],v});
			}
		}
	}
}
__inline void bfs(int x){
	for(int i=0;i<=n+m+2;i++){
		st[i]=0;
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	queue<int>pq;
	pq.push(x);
	dis[x]=0;st[x]=1;
	while(!pq.empty()){
		int u=pq.front();
		pq.pop();
		for(auto i:ve2[u]){
			if(st[i]) continue;
			st[i]=1;
			dis[i]=dis[u]+tt*2;
			pq.push(i);
		}
	}
}
#define A 9<=c&&c<=11
#define B 12<=c&&c<=19
bool BB;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>tt;
			ve[i+m].push_back({a,tt});
			ve[a].push_back({i+m,tt});
		}
	}
	if(A){
		for(int i=1;i<=m;i++){
			Dijkstra(i);
			for(int j=1;j<=m;j++){
				ddis[i][j]=dis[j];
				ddis[j][i]=dis[j];
			}
		}
	}
	if(B){
		for(int i=1;i<=m;i++){
			for(int j=0;j<ve[i].size();j++){
				for(int k=j+1;k<ve[i].size();k++){
					ve2[ve[i][j].first-m].push_back(ve[i][k].first-m);
					ve2[ve[i][k].first-m].push_back(ve[i][j].first-m);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				ddis[i][j]=ddis[j][i]=dis[j];
			}
		}
	}
	while(q--){
		cin>>x>>y;
		if(c<=8){
			Dijkstra(x);
			cout<<w[x]+w[y]+dis[y]<<"\n";
		}
		else if(A){
			cout<<w[x]+w[y]+ddis[x][y]<<"\n";
		}
		else if(B){
			int mx=0x3f3f3f3f3f3f3f3f;
			for(auto i:ve[x]){
				for(auto j:ve[y]){
					mx=min(mx,ddis[i.first-m][j.first-m]);
				}
			}
			cout<<w[x]+w[y]+mx+tt*2<<"\n";
		}else{
			cout<<w[x]+w[y]+ve[x][0].second+ve[y][1].second+tt*2<<"\n";
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

12 2 4 2 1
0 0 0 0
3 1 1 2 1 3 1
3 2 1 3 1 4 1
1 4
*/ 

