#include<bits/stdc++.h>

#define LL long long 
using namespace std;
#define sf cout << "\safe\n" << flush
const int maxn = 2e6+5;
int n, d;
LL a[maxn];
LL cf[maxn];
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		bool isA=1,isB=1,isC=1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cf[i] = a[i] - a[i-1];
		}
		for (int i = 3; i<= n; i++ )
		{
			if (cf[i] !=cf[i-1]) {
				isA =0;
				break;
			}
		}
		if (n==1 ) {
			cout << 0 << endl;
			continue;
		}
		if (isA) {
			cout << max(n  - 2 * d / cf[2], 0ll) << endl;
			continue;
		} else { // B
			int cnt = 0;
			LL l,r=1;
			for (int i = 1; i <= n; i++) 
				if (a[i] - a[1] <= d && a[n]-a[i]<=d) cnt++,l= r ,r = i;
			if (cnt > 2) cout << 0 << endl;
			else if (cnt == 2) cout << (l-1) *(n-r) << endl;
			else cout <<(r-1) * (n-r) << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
