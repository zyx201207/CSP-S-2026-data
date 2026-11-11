#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll c,t;
vector<ll> tree[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			ll x,y;
			cin>>x>>y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		if(k<=2){
			cout<<0<<'\n';
		}
	}
	return 0;
}//?+?+8+12=20+?+?+?
//O(???)











//luogu name:will0804
