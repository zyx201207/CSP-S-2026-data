#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,t,d;
const ll N=2e6+5;
vector<ll>g[N];
ll x[N];
struct node{
	ll now,poc;
};
bool bfs(ll u,ll v){
	queue<node >q;
	q.push({u,1});
	node lu;
	ll luc=0;
	lu.poc=2e18+5;
	while(!q.empty()){
		node t=q.front();
		q.pop();
		if(t.poc<=n){
			if(t.now==v){
				if(lu.poc>t.poc){
					lu.poc=t.poc;
					luc=1;
				}
				else if(lu.poc==t.poc){
					luc++;
				}
			}
			else{
				for(ll i=0;i<g[t.now].size();i++){
					q.push({g[t.now][i],t.poc+1});
					
				}
			}
		}	
	}
	return luc==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(g,-1,sizeof(g));
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}	
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(bfs(i,j)==true){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";	
	}
}
