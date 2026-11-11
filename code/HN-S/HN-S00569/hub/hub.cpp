#include<bits/stdc++.h>
// #define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1,x;i<n;i++)cin>>x>>x;
		cout<<(n==k?0:1)<<'\n';
	}
	return 0;
}