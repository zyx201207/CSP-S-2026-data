#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=2e6+5;
int c,t,n,d,a[N];
void solve(){
	if (c==11||c==12||c==0) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<a[n]-a[1]-d<<"\n";
	}
}
signed main(){	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
