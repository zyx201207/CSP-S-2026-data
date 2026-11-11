#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t;
int n,k;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1,u,v;i<n;i++)cin >> u >> v;
		if(k==n){
			cout << 0 << '\n';
			continue;
		}
		int ans=max(((n+5)/2-k+3)/4,0);
		cout << ans << '\n';
	}
	return 0;
}
