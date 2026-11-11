#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
typedef pair<int,int>PII;
vector<PII>a[N];
int dis[N],w[N];
int k,n,d,t;
void dijkstra(int s){
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> > h;
	h.push({0,s});
	while(!h.empty()) {
		int u=h.top().second,w=h.top().first;
		h.pop();
		if(w>dis[u])continue;
		for(auto x:a[u]) {
			int v=x.first,w=x.second;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				h.push({dis[u]+w,v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c;
	cin>>c;
	if(1) {
		cin>>k>>n>>d>>t;
		for(int i=1;i<=n;i++) {
			cin>>w[i];
		}
		for(int i=1;i<=k;i++){
			int b;
			cin>>b;
			int s,t,e,tt;
			cin>>s>>t>>e>>tt;
			a[s].push_back({e,t+tt});
			a[e].push_back({s,t+tt});
		}
		while(t--) {
			int s,e;
			cin>>s>>e;
			dijkstra(s);
			cout<<dis[e]+w[s]+w[e]<<'\n';
		}
	}
	return 0;
}

