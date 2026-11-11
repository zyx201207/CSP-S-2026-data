#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(k==n) cout<<0;
		else cout<<1;
		cout<<"\n";
	}
	return 0;
}
