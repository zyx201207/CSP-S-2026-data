#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans = 0;
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;++i) {
		cin>>a[i]>>c[i];
	}
	int i = 1,j = n;
	while (i <= j) {
		if (a[i] >= a[j]) {
			if (c[i] != c[j]) {
				ans += (a[j]);
			}
			a[i] -= a[j];
			a[j] = 0;
			if (a[i] == 0) {
				++i;
			}
			--j;
		}
		else {
			if (c[j] != c[i]) {
				ans += (a[i]);
			}
			a[j] -= a[i];
			a[i] = 0;
			++i;
		}
	}
	cout<<ans;
	return 0;
}
