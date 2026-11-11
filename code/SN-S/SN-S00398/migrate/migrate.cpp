#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int ans = 0;
		int n,d;
		cin >> n >> d;
		int x[100005];
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			if(x[i + 3] <= x[i] + 2 * d){
				ans++;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
