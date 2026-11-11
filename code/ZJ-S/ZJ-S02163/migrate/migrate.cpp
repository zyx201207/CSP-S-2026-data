#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int s=min(n,d/(a[2]-a[1]));
		if(s<=1){
			cout<<0<<endl;
			continue;
		}
		int ans=n-2*s+1;
		if(ans<0) cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
