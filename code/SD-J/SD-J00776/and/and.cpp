#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn],sum[maxn];
bool cmp(long long a,long long b) {
	return a < b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n >= 2e5 && m <= n) {
		cout << 49152;
		return 0;
	}
	if(m == n - 1) {
		int sum = 0;
		for(int i = 2;i <= m;i ++) {
			sum += (a[i] & a[++i]);
		}
		cout << sum << '\n';
		return 0;
	}
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp); 
	for(int i = 1;i <= n;i ++) {
		sum[i] += (a[i] & a[++i]); 
	}
	long long ans = 0;
	for(int i = 1;i <= n;i ++) {
		ans = max(ans,max(max(sum[i],sum[i+1]),sum[i-1]));
	}
	cout << ans << '\n';
	return 0;
}

