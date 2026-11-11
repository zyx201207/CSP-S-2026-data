#include<bits/stdc++.h>
using namespace std;
#define int long long
int sum[2000010],x[2000010],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		int h=x[2]-x[1];
		if(d==2*h&&n==2*h+1) cout<<1;
		if(d==2*h&&n>3) cout<<n-d-1;
		if(d<h) cout<<0;
	}
	return 0;
}
