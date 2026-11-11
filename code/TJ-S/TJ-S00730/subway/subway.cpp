#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,m,tmp,q,w[200005],f[400005],vis[200005];
vector<pair<int,ll> >e[400005];
void dij(int s){
	f[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v=0;v<e[u].size();v++){
			if(f[e[u][v].first]>f[u]+e[u][v].second){
				f[e[u][v].first]=f[u]+e[u][v].second;
				q.push((pair<int,int>){f[e[u][v].first],e[u][v].first});
			}
		}
	}
	return;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>tmp>>n>>m>>tmp>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	ll l,fei;
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>tmp>>fei;
			e[i+m].push_back({tmp,fei});
			e[tmp].push_back({i+m,fei});
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n+m;j++) vis[j]=0,f[j]=2e9;
		cin>>x>>y;
		dij(x);
		cout<<f[y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
