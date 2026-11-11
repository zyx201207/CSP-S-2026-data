#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define ll long long
#define rnt register int
#define A first
#define B second
int c,T,n,d,a[N];
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ll ans=0;
		for(rnt i=1;i<=n;++i) cin>>a[i];
		int t=d/(a[2]-a[1])*2;
		if(n<=3||t>=n) cout<<0<<'\n';
		else{
			for(rnt i=4;i<=t;i+=2)
				ans+=n-i+1;
			cout<<ans<<'\n';
		}
	}
}


