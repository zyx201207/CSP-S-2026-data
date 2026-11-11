#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e6+7;
int c,t,n,d;
long long a[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		int ans = 0;
		for(int i = 0; i < n; i++) cin >> a[i];
		if(d==1||n <= 3) cout << 0 << endl;
		for(int u = 0; u < n-3; u++){
			for(int v = u+3; v < n; v++){
				if(a[v]-a[u]==2*d-1) {
					ans++;	
				}
			}
		}
		cout << ans << endl;
	}
}
