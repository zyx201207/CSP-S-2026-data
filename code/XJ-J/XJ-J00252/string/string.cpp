#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, ans, a[N], tot, b[N], j, rt, st, idx;
char c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		tot += a[i];
		b[i] = tot;
	}
	j = n, rt = tot;
	for (int i = 1; i <= n && b[i] * 2 <= tot; i ++){
		st = b[i], idx = i;
		while (rt * 2 >= tot && rt - a[i] <= b[j-1]){ 
			a[i] -= (rt - b[j-1]);
			if (c[i] != c[j])
				ans += rt - b[j-1];
			j --;
			rt = b[j];
		}
		if(a[i] > 0){
			if(c[i] != c[j])
				ans += a[i];
			rt -= a[i];
		}
	}
	if(st * 2 <= tot){
		st = tot / 2 - st;
		while (rt * 2 >= tot && rt - st <= b[j-1]){ 
			st -= (rt - b[j-1]);
			if (c[idx + 1] != c[j])
				ans += rt - b[j-1];
			rt = b[--j];
		}
	}
	cout << ans;
	return 0;
}
