#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,d;
void solve() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
	}
	int ans=n/2-d/2;
	cout<<ans<<"\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		solve();
	}
	return 0;
}
