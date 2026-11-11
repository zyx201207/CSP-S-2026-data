#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 20005;

struct Edge{
	ll v,w;
};

ll T,k[505],w[M],c,n,m,d,q,a[505][M],t[505][M],dis[M];
bool flag1=1,flag2=1,vis[M];
vector<Edge> edge[M];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				edge[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				edge[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
			}
		}
	}
}
void dij(int st){
	priority_queue< pair<ll,int> > pq;
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		pair<ll,int> t=pq.top();
		pq.pop();
		ll w = t.first;
		int u = t.second;
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(int j=0;j<edge[u].size();j++){
			Edge i = edge[u][j];
			if(dis[i.v]>i.w+w){
                dis[i.v]=i.w+w;
                //cout<<u<<" "<<i.v<<" "<<dis[i.v]<<endl;
                pq.push(make_pair(dis[i.v],i.v));
			}
		}
	}
}
ll solve(int st,int ed){
	dij(st);
//	for(int i=1;i<=m;i++){
//		cout<<dis[i]<<" ";
//	}
    return w[st]+w[ed]+dis[ed];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			flag1=0;
		}
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	T=t[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(t[i][j]!=T){
				flag2=0;
			}
		}
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			if(k[i]==2){
				edge[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
				edge[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<solve(x,y)<<endl;
		}
		return 0;
	}
	init();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7

4


5 5
1 2 4 8 9

3
*/

