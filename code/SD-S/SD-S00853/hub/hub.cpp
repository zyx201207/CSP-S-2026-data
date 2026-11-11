#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n,k;
const int N=1e6+10;
vector<int> g[N];
void solve(){
	cin>>n>>k;
	for (int i=1; i<n; i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n==k){
		cout<<"0\n";
		return;
	}
	int cnt=0;
	for (int i=1; i<=n; i++){
		if (g[i].size()==1) cnt++;
	}
	cnt=n-cnt-1;
	if (k>=cnt){
		cout<<"1\n";
		return;
	}
	if (13<=c&&c<=14){
		if (k>=(n/2)){
			cout<<"1\n";
			return;
		}
		cout<<((n/2)+2-k+1)/2<<'\n';
		return;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

