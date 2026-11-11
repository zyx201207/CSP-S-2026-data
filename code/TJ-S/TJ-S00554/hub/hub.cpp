#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,wz[2000005],f[305][305],ans[305][305];
void solve(){
	cin>>n>>d;
	for(int i=1;i<n;i++)cin>>wz[i];
	cout<<1ll*(n/d-1)<<'\n';
}
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}


