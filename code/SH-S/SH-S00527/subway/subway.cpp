#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define endl '\n'
const int N=5e5+500+5;
int c,n,m,d,q,w[N];
ll dis[N];
vector<pii> g[N];
//Õ¾Ì¨±àºÅ1-m 
//ÏßÂ·±àºÅm+1-m+n 
void add(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
void dj(int s){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=m+n;i++)dis[i]=1e18;
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(t.first!=dis[u])continue;
		for(auto j:g[u]){
			int v=j.first,w=j.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
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
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			add(i+m,u,w);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dj(u);
		cout<<w[u]+w[v]+dis[v]<<endl;
	}
	
	return 0;
} 
