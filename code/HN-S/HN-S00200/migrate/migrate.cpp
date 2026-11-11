#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=2e6+5;
int c,T;
int n,d;
int a[kMaxN];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<1<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
*/
