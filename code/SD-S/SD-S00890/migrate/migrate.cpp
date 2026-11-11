#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,a[N],ans;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(d/(a[2]-a[1])<2) cout<<"0\n";
	else cout<<n-2-d/(a[2]-a[1])<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
