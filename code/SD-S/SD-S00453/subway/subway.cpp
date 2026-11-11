#include<bits/stdc++.h>
using namespace std;   

#define int long long
#define pii pair<int,int>
const int M=5e5+5;
const int N=505;
int c,n,m,D,q;
int w[M];

vector<pii>g[M+N];

int d[M];
void dijk(int s){
	memset(d,0x3f,sizeof(d));
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,s});d[s]=0;
	while(q.size()){
		pii t=q.top();q.pop();
		int dis=t.first,u=t.second;
		if(dis!=d[u])continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		while(k--){
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijk(x);
		cout<<w[x]+w[y]+d[y]<<'\n';
	}
	return 0;
}
