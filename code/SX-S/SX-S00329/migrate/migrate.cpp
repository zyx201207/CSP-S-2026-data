#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000010];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int dif=a[2]-a[1];
		int k=d/dif;
		if(d==1||(2*k-1)>n||k==1||k==0)cout<<0<<"\n";
		else cout<<max(0ll,n-(2*k-1))<<"\n";
	}
	return 0;
}
