#include<iostream>
#include<vector>
#include<algorithm>
#define int long long

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	std::cin>>n>>m;
	std::vector<int> a(n+1, 0);
	for (int i=1; i<=n; i++)
		std::cin>>a[i];
	sort(a.begin()+1, a.end(), std::greater<int>());
	int ans=0;
	int l=1, r=n;
	for (int k=30; k>=0; k--) {
		int cnt=0;
		for (int i=l; i<=r; i++)
			cnt+=((a[i]>>k)&1);
		int nl=l, nr=r;
		for (int i=l; i<=r; i++)
			if ((a[i]>>k)&1) {
				nl=i;
				break;
			}
		for (int i=r; i>=l; i--)
			if ((a[i]>>k)&1) {
				nr=i;
				break;
			}
		if (cnt>=m) {
			ans+=(1<<k);
			l=nl, r=nr;
		}
	}
	std::cout<<ans;
	return 0;
}
