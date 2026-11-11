#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,t;
int n,k;
vector<int>mp[N];
bool check(int t){
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	if(k==1) cout<<n/2<<"\n";
	else cout<<(n-(k-2))/3<<"\n";
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

