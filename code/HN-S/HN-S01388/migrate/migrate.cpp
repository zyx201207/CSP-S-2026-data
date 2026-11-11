#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,t;
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		if (a[4] - a[1] <= d)
			cout << n - 3 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
