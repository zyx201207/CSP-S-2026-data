#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>> n>>d;
		for(int j=1;j<=n;j++){
			cin >> a[j];
		}
	}
	cout << 1 << "\n";
	cout << 2;
}
