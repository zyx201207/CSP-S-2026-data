#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) {
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++) {
			int u,v;cin>>u>>v;
		}
		if(k==n) cout<<0<<"\n";
		else if((n-k)/3==0) cout<<1<<"\n";
		else cout<<(n-k)/3<<"\n";
	}
	return 0;
}