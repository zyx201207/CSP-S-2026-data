#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;

int n,m,a[N],ans;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int sum = 0;
	for(int i = 1,j = 1;j<=n;j++) {
		sum += ((j - i) * (a[j] - a[j-1]));
		while(i < j && sum > m) {
			sum -= (a[j] - a[i]);
			i++;
		}
		ans = max(ans,j - i + 1);
	}
	cout << ans;
	return 0;
}
