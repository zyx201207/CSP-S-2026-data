#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++){
		int n,k;
		cin >> n >> k;
		int u[n+1],v[n+1];
		for(int i = 1;i <= n-1;i++){
			cin >> u[i] >> v[i];
		}
		long long ans = 1;
		
		cout << ans << '\n';
	}
	return 0;
}
