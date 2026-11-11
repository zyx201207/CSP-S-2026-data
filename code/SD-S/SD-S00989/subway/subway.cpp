#include<bits/stdc++.h>
using namespace std;
const int N=5e5+500+10;
int c,n,m,d,q;
int w[N];
int vis[N];
unsigned long long dis[N];
vector<pair<int,int> > g[N];
void D(int x){
	for(int i=1;i<=m+n;i++) vis[i]=0,dis[i]=LLONG_MAX;
	priority_queue<pair<unsigned long long,int>,vector<pair<unsigned long long,int> >,greater<pair<unsigned long long,int > > > q;
	dis[x]=0;
	q.push({dis[x],x});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]) q.push({dis[v],v});
			}
		}
	}
	return ;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,last=0;
		cin>>k;
		for(int s=1;s<=k;s++){
			int a,b,t;
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	
	while(q--){
		int s1,s2;
		cin>>s1>>s2;
		D(s1);
		cout<<dis[s2]+w[s1]+w[s2]<<"\n";
	}
	return 0;
}

