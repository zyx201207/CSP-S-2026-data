#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s,z;
ll C,n,m,d,q; 
ll w[500005];
struct rce{
	ll id;
	ll t;
};
vector<ll>a[505];//联通否？ 
vector<ll>c[500005];
map<pair<ll,ll>,ll>t;//站台到哪个线路要多久？ 
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>qu;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		ll k;
		cin>>k;
		for(int j=1; j<=k; j++){
			ll b,tt;
			cin>>b;
			a[i].push_back(b);
			cin>>tt;
			t[{b,i}]=tt;
			c[b].push_back(i);
		}
	}
	while(q--){
		cin>>s>>z;
		qu.push({0,s});
		while(qu.size()){
			ll x=qu.top().second;
			ll cnt=qu.top().first;
			qu.pop();
			if(x==z){
				cout<<cnt<<"\n";
				break;
			}
			for(auto y:a[x]){
				ll ans1=cnt+t[{y,x}];
				for(auto z1:c[y]){
					ll v=t[{y,z1}];
					ans1+=v;
					qu.push({z1,ans1});
					ans1-=v;
				}
			}
		} 
		while(qu.size()) qu.pop();
	} 
	return 0;
}

//0

