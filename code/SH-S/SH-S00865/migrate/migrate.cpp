#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(d/(x[n]-x[n-1])>=2&&n-2*d/(x[n]-x[n-1])+1>=0)cout<<n-2*d/(x[n]-x[n-1])+1;
		else cout<<0;
		cout<<'\n';
	}
	return 0;
}

