#include <bits/stdc++.h>
#define Pair pair<long,long>
#define int long long
using namespace std;
int c,n,m,o,q,k,x,y,a[500010],d[500510];
struct node{
	int v,w;
};
vector<node> ve[510],e[500510];
void dij(){
	for(int i=1;i<=n+m;i++)d[i]=1e18+10;
	priority_queue<Pair,vector<Pair>,greater<Pair>> q;
	q.push({0,x});
	d[x]=0;
	while(!q.empty()){
		Pair now=q.top();
		q.pop();
		int u=now.second,val=now.first;
		for(int i=0;i<e[u].size();i++){
			node v=e[u][i];
			if(d[v.v]>val+v.w){
				d[v.v]=val+v.w;
				q.push({d[v.v],v.v});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>o>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		while(k--){
			cin>>x>>y;
			ve[i].push_back({x,y});
			e[n+i].push_back({x,y});
			e[x].push_back({n+i,y});
		}
	}
	while(q--){
		cin>>x>>y;
		dij();
		cout<<a[x]+a[y]+d[y]<<"\n";
	}
	return 0;
}
