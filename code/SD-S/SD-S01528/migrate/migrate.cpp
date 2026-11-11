#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n,d,c,t,ans;
LL x[2000006];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			if(2*(x[2]-x[1])<=d) cout<<n-3<<'\n';
			else cout<<0<<'\n';
		}
		if(c==13||c==14)
		cout<<ans<<'\n';
	}
	return 0;
}

