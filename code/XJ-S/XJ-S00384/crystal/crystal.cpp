#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5+78;

ll a[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int mid = a[(n+1) / 2];
	int idx = 1;
	while (m--) {
		if (a[idx] != mid) {
			a[idx]++;
		} else if (a[idx] == mid) {
			idx++;
			m++;
		}
		if (idx == (m+1) / 2) {
			break;
		}
	}
	while (m > 0) {
		if (m / idx >= 1) {
			m -= idx;
			for (int i = 1;i <= idx;i++) {
				a[i]++;
			} 
			if (a[idx] == a[idx+1]) {
				idx++;
			}
		} else {
			break;
		}
	}
	printf("%d",idx+2);
  	
	return 0;
}
