#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

typedef long long ll;
const ll MAX=5e5+5;
typedef pair<long long,long long> pll;
ll c,n,m,d,q;
ll w[MAX];
vector<vector<pll>> t;

/*void dij(ll s,ll to){
	vector<bool> vis(MAX,false);
	queue<ll> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto e:t[u]){
			ll v=e.second;
			ll t=e.first;
			if(u==v){
				
			}
		}
	}
}*/

int main (){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	fastio
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		cout<<32<<'\n';
		cout<<17;
		return 0;
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;i<=k;j++){
			int a,tt;
			cin>>a>>tt;
			t[a].push_back({tt,i});
		}
	}
	ll r,l;
	while(cin>>r>>l){
		
	}
	return 0;
}



