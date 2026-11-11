#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
bool book[N];
int w[N],len[N];
typedef pair<int,int> PII;
typedef pair<int,PII> PIP;
vector<PII> g[N];
	int c,n,m,d,q;
void dijkstra(int x){
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,x});
	len[0]=0;
	while(!q.empty()){
		int u=q.top().second,v=q.top().first;q.pop();
		len[u]=v;
		for(auto o:g[u]){
			if(len[o.second]==0&&o.second!=x||len[o.second]>v+o.first){
				q.push({v+o.first,o.second});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({t,i+m});
			g[i+m].push_back({t,a});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		dijkstra(u);
		cout<<len[v]+w[u]+w[v]<<"\n";
		for(int i=1;i<=n+m;i++){
			len[i]=0;
		}
	}
	return 0;
}
