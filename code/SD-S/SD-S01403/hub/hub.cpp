#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		vector<vector<int>>ar(n+1);
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			ar[u].push_back(v);
			ar[v].push_back(u);
		}
	}
	return 0;
}
