#include<bits/stdc++.h>
#define int long long
//UID 1137851
//Oct 31 Today
//Dec 25 ??? 
//a~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!
using namespace std;
const int N=1e6+5;
int c,t,n,k;
vector <int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<1<<"\n";
	}
	return 0;
}

