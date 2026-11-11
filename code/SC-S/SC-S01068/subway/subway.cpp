#include<bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
int c,n,m,d,q;
const int N=5e5+5;
int w[N];
vector<PII> g[N];
int dist[N],flag[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=m+1;i<=m+n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({t,a});
			g[a].push_back({t,i});
//			cout<<a<<' '<<i<<"\n";
		}
	}
	while(q--){
		int s,r;
		cin>>s>>r;
		priority_queue<PII,vector<PII>,greater<PII> > q;
		memset(dist,0x3f,sizeof dist);
		memset(flag,0,sizeof flag);
		dist[s]=0;
		q.push({0,s});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(flag[u])continue;
			flag[u]=1;
			for(int i=0;i<(int)g[u].size();i++){
				int v=g[u][i].second,w=g[u][i].first;
//				cout<<dist[v]<<' '<<dist[u]+w<<'\n';
				if(dist[v]>dist[u]+w){
					
					dist[v]=dist[u]+w;
					q.push({dist[v],v});
				}
			}
		}
		cout<<dist[r]+w[s]+w[r]<<'\n';
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
*/