#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[500001],ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	long long l = 1,r = 1,rest = m;
	while (l <= r && r <= n){
		while ((r-l+1) * (a[r+1] - a[r]) <= rest && r < n){
			rest -= (r-l+1) * (a[r+1] - a[r]);
			r++;
		}
		
		ans = max(ans,r-l+1);
		rest += a[r] - a[l];
		if (l == r && r != n) l++,r++;
		else l++;
	}
	cout << ans;
	return 0;
}
