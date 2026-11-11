#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+79;
const int INF = 1e9+78916666;

ll a[N];
int n,m;

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll x = a[n];
	n--;
	int mx = 0;
	while (m--) {
//		printf("m:%d\n",m);
		int idx = 0;
		for (int i = 1;i <= n;i++) {
			if (x & a[i] > mx) {
				mx = (x & a[i]);
				idx = i;
			}
//			printf("  i:%d  x:%lld  mx:%lld idx:%d  (x & a[i]):%d  a[i]:%lld\n",i,x,mx,idx,(x&a[i]),a[i]);
		}
		a[idx] = INF;
		sort(a+1,a+n+1);
		n--;
		x = mx;
//		printf("  n:%d  x:%d\n",n,x);
//		for (int i = 1;i <= n;i++) {
//			printf("  i:%d  a[i]:%lld\n",i,a[i]);
//		}
	}
	cout << x;
	
	return 0;
}
