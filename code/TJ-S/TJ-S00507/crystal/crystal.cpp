// rp++
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[500010];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	int i=1, j=1, ans=1;
	while(j<n) {
		j++;
		m-=(a[j]-a[j-1])*(j-i);
		while (m<0) {
			m+=a[j]-a[i];
			i++;
		}
		ans=max(ans, j-i+1);
	}
	cout << ans;
	return 0;
}
