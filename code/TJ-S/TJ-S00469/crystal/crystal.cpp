#include <bits/stdc++.h>
#define int long long//5e17
#define N 500005
using namespace std;
int n,m,a[N],sum,ans;
signed main(){
	#ifndef HONGXIAODOU
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#endif
	cin >> n >> m;
	for (int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + n + 1);//²»±£Ö¤Ë³Ðò
	ans = 1;
	for (int i = 1,j = 1;i <= n;++i){
		sum += (i - j) * (a[i] - a[i - 1]);
		while (sum > m && j < i){
			sum -= a[i] - a[j];
			++j;
		}
		ans = max(ans,i - j + 1);
	}
	cout << ans;
return 0;
}
