#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005];
bool f = true;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		int x = a[2] - a[1];
		for(int i = 3;i <= n;i++) if(a[i] - a[i - 1] != x) f = false;
		if(f){
			if(d < x){
				cout << 0 << "\n";
				continue;
			}
			else{
				cout << (n + 1) / d - 1 << "\n";
				continue;
			}
		}
	}
	return 0;
}
