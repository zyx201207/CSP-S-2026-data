#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,q;
ll w[500010];
//ll a[500][];
vector<ll> edge[500010];
map<ll,ll> dist[500010];


int main(){
	srand(time(NULL));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		ll y;
		for(ll j=1;j<=x;j++){
			cin>>y;
//			edge[]
		}
	}
	while(q--){
		ll st,ed;
		cin>>st>>ed;
		cout<<rand()<<endl;
	}
	return 0;
}
