#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+20;
int c,t,n,d,x[N],sum;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>t;

	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>x[i];
		int d1=x[2]-x[1];
		int s=d/d1;
		if(s==1) cout<<0<<"\n";
		else cout<<n-1<<"\n";
	}

	return 0;
}
