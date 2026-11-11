#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k;
vector<int> a[1000005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(n==k)cout<<"0\n";
		else cout<<"1\n";
	}
	return 0;
}
