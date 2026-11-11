#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int cnt=0;
void solve(){
	cout<<++cnt<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}