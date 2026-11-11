#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans = 0;
void dfs (long long idx,long long cnt,long long s) {
	if (s <= ans) {
		return;
	}
	if (n - idx < m - cnt) {
		return;
	}
	if (cnt == m) {
		ans = max (s,ans);
		return;
	}
	for (int i = idx + 1;i <= n;++i) {
		dfs (i,cnt + 1,s & a[i]);
	}
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;++i) {
		cin>>a[i];
	}
	sort (a + 1,a + 1 + n,greater <int> ());
	for (int i = 1;i <= n - m + 1;++i) {
		dfs (i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
