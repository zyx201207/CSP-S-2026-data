#include<bits/stdc++.h>
#define int long long
using namespace std;
void A(int T){
	while(T--){
		int n,m;
		cin>>n>>m;
		int k,q;
		for(int i=1;i<=n;i++) cin>>k>>q;
		int u=(n-1)/2;
		if(k<u) cout<<ceil((n-u)/3)+1<<'\n';
		else if(k>=u&&k<n) cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==11||c==12){
		A(T);
		return 0;
	}
	return 0;
}
