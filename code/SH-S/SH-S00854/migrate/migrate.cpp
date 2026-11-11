#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,q,n,m,a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>q;
	if(c==11||c==12){
		while(q--){
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			int d=a[2]-a[1];
			if(d*2>m)cout<<0<<'\n';
			else cout<<max(n-m/d*2+1,0*1ll)<<'\n';
		}
	}
	return 0;
} 
