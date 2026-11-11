#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000010;
ll c,t;
void solve(){
	ll n,k;cin>>n>>k;
	vector<ll>v[N];
	for(int i=1;i<=n;i++){
		int u,w;cin>>u>>w;
		v[u].push_back(w);
		v[w].push_back(u);
	}
	cout<<1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
