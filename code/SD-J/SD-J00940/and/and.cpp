#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	int i = 0;
	while(i < m) {
		long long t = 0;
		for(int j = i; j < m - 1; j++) {
			t += a[j] & a[j + 1];
		}
		ans = max(ans,t);
		i++;
	}
	cout << ans;
	return 0;
}
