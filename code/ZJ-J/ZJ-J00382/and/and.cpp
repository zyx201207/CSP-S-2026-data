#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long a[N],ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			ans = max(ans,a[i] & a[j]);
		}
	}
	cout << ans;
	return 0;
}