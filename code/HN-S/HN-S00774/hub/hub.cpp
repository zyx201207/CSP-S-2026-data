#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,x,y;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>x>>y;
		if(k==n) cout<<"0\n";
		if(k>=n/2) cout<<"1\n";
		if(k<n/2) cout<<(n/2+5-k)/4<<"\n"; 
	}
	return 0;
}
