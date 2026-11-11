#include<bits/stdc++.h>
using namespace std;
const int W=2e7+5,M=5e5+5,N=505;
int c,n,m,d,q,w[M],k[N],x[M];
long long v[W];
vector<pair<int,int> > g[W],a[M];
map<int,int> ma;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int y;
			cin>>x[j]>>y;
			a[x[j]].push_back({i-1,y});
			ma[x[j]+(i-1)*m]=y;
			if(j>1){
				g[x[j]+(i-1)*m].push_back({x[j-1]+(i-1)*m,0});
				g[x[j-1]+(i-1)*m].push_back({x[j]+(i-1)*m,0});
			}
		} 
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int l=j+1;l<a[i].size();l++){
				if(j==l) continue;
				g[m*a[i][j].first+i].push_back({m*a[i][l].first+i,a[i][j].second+a[i][l].second});
				g[m*a[i][l].first+i].push_back({m*a[i][j].first+i,a[i][j].second+a[i][l].second});
			}
		}
	}
	for(int i=1;i<=(n+1)*m;i++) v[i]=1e18;
	while(q--){
		int o,oo;
		cin>>o>>oo;
		priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
		for(int i=0;i<a[o].size();i++){
			v[a[o][i].first*m+o]=a[o][i].second;
			q.push({a[o][i].second,a[o][i].first*m+o});
		}
		while(q.size()){
			long long w1=q.top().first;
			int u=q.top().second;
			q.pop();
			for(int i=0;i<g[u].size();i++){
				long long w2=w1+g[u][i].second;
				if(v[g[u][i].first]>w2){
					v[g[u][i].first]=w2;
					q.push({w2,g[u][i].first});
				}
			}
		}
		long long ans=1e18;
		for(int i=1;i<=(n+1);i++){
			if(v[m*(i-1)+oo]+ma[m*(i-1)+oo]<ans){
				ans=v[m*(i-1)+oo]+ma[m*(i-1)+oo];
			}
		}
		cout<<ans+w[o]+w[oo]<<'\n';
	}
}
