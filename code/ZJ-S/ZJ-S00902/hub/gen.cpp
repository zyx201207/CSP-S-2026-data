#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
int T=0;
signed main()
{
	freopen("hub.in","w",stdout);
	rep(n,1,10){
		rep(k,2,n) T++;
	}
	cout<<0<<" "<<T<<"\n";
	rep(n,1,10){
		rep(k,2,2*n+1){
			cout<<n*2+1<<" "<<k<<"\n";
			rep(i,1,n) cout<<i<<" "<<i+1<<"\n";
			rep(i,n+1,2*n) cout<<i-n<<" "<<i+1<<"\n"; 
		}
	}
	return 0;
}
