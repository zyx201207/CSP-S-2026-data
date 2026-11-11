#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
int a[N];int cnt;int tot;
vector<pair<int,int> >v[N];
vector<pair<int,int> >id[N];int dis[N/10],vis[N/10];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qu;
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	qu.push({dis[s],s});
	while(!qu.empty()){
		pair<int,int>t=qu.top();
		qu.pop();
		int f=t.second,w=t.first;
		if(vis[f])continue;
		vis[f]=1;
		for(int i=0;i<v[f].size();i++){
			int to=v[f][i].first,ww=v[f][i].second;
			if(dis[to]>dis[f]+ww){
				dis[to]=dis[f]+ww;
				qu.push({dis[to],to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	tot=n;
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		while(k--){
			cin>>a>>t;
			id[a].push_back({++tot,t});
			v[i].push_back({tot,0});
			v[tot].push_back({i,0});
		}
	}
	for(int i=1;i<=m;i++){
		++tot;
		for(int j=0;j<id[i].size();j++){
			v[tot].push_back({id[i][j].first,id[i][j].second});
			v[id[i][j].first].push_back({tot,id[i][j].second});
		}
	}
	cnt=tot;
	for(int i=1;i<=m;i++){
		++tot;
		v[tot].push_back({cnt-m+i,w[i]});
		v[cnt-m+i].push_back({tot,w[i]});
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		dij(cnt+x);
		cout<<dis[cnt+y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/