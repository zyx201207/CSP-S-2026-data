#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,Q;
int w[500010],k[100010];

struct Node{
	int nxt,w;
};
vector<Node>e[1000010];
void add(int u,int v,int w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
	return;
}
ll dis[2000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int A,T;
			cin>>A>>T;
			add(m+i,A,T);
		}
	}
	int X,Y;
	
	while(Q--){
		cin>>X>>Y;
		memset(dis,0x3f3f3f,sizeof dis);
		int s=X;
		dis[s]=0;
		priority_queue<pair<int,ll>,vector<pair<int,ll> >,greater<> >q;
		q.push({s,0});
		while(!q.empty()){
			pair<int,ll>z=q.top();
			q.pop();
			int df=z.first;
			for(int i=0;i<e[df].size();i++){
				if(dis[e[df][i].nxt]>dis[df]+e[df][i].w){
					dis[e[df][i].nxt]=dis[df]+e[df][i].w;
					q.push({e[df][i].nxt,dis[e[df][i].nxt]});
				}
			}
		}
		cout<<w[X]+w[Y]+dis[Y]<<'\n';
	}
	return 0;
}
