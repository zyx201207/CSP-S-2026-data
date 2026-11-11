#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using i128 = __int128;

const int N = 5e5 + 100;

int n;
LL m, a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	vector<i128> s(n + 1);
	for(int i = 1;i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n; i ++)
		s[i] = s[i - 1] + a[i];


	if(n >= 5000){
		int ans = 0;
		
		for(int i = 1; i <= n; i ++){
			int l = 1, r = i - 1;
			int c;
			i128 sum;
			while(l < r){
				int mid = l + r >> 1;
				c = i - 1 - mid + 1;
				sum = s[i - 1] - s[mid - 1];
			
				if((i128)a[i] * c - sum <= m)	r = mid;
				else	l = mid + 1;
			}
			c = i - 1 - r + 1;
			sum = s[i - 1] - s[r - 1];

			if((i128)a[i] * c - sum <= m)
				ans = max(ans, i - r + 1);
		}
		cout << ans << '\n';
	} else {
		int res = 0;
		for(int i = 1;i <= n; i ++){
			LL x = m, p;
			int ans = 1;
			for(int j = i - 1; j >= 1; j --)
				if(x >= a[i] - a[j])
					x -= a[i] - a[j], ans ++;
				else{
					p = j;
					break;
				}
			res = max(res, ans);

		}
		cout << res;
	}
	
	
	return 0;
}
