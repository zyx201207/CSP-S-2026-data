#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;
int n, m, a[N], s[N], ans = 1, p[N], sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = n - 1;i >= 1;--i){
		sum += a[i + 1] - a[i];
		s[i] = s[i + 1] + sum;
		p[i] = sum;
	}
	for(int i = 2;i <= n;++i){
		int l = 1, r = i, del = s[i + 1];
		while (l <= r) {
			int mid = (l + r) >> 1;
			if(s[mid] - s[i] - (i - mid) * p[i] <= m) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}
