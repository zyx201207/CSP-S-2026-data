#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+10;

int n,m,ans;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int l = 1,r = 1,s = 0,cnt = 0;
	while (l <= r && r <= n){
		while (s + (cnt+1)*(a[r+1]-a[r]) <= m && r < n){
			r++,cnt++;
			s += cnt * (a[r] - a[r-1]);
		}
		if (r-l+1 > ans)ans = r-l+1;
		r++,cnt++;
		s += cnt * (a[r] - a[r-1]);
		while (s > m){
			s -= (a[r]-a[l]);
			l++,cnt--;
		}
	}
	cout << ans;
	return 0;
}
