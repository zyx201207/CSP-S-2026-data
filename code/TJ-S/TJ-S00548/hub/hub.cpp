#include<bits/stdc++.h>
#define int long long
int c,t,n,k,u,v;
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>u>>v;
		int m=(n-1)/2;
		int p=m/4;
		if(k==1)cout<<2*p+1;
		else if(k>=m)cout<<1;
		else if(m%4==0){
			int ans=(4*p+7-k)/4;
			cout<<ans;
		}
		else if(m%4==3){
			int ans=(4*p+11-k)/4;
			cout<<ans;
		}else{
			int ans=(4*p+9-k)/4;
			cout<<ans;
		}
		cout<<'\n';
	}
	return 0;
} 
