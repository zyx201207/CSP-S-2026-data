#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N], f[N];
bool flag[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i ++) f[i] = a[i + 1] - a[i];
	f[0] = f[1];
	bool flag1 = true, flag2 = true;
	for(int i = 1; i < n; i ++){
		if(f[i] != 1) flag1 = false;
		if(f[i] != f[i - 1]) flag2 = false;
	}
	
	if(flag1 == true || flag2 == true){
		int cnt = 0, sum = 0, ans = 1;
		for(int size = 1; size <= n; size ++){
			int mid = (1 + size) / 2;
			sum = 0;
			for(int i = 1; i <= size; i ++)
				sum += abs(a[i] - a[mid]);
			if(sum <= m) ans = size;
		}
		cout << ans << endl;
	}
	else{
		int ans = 0, res;
		for(int size = 1; size <= n; size ++){
			for(int start = 1; start <= n - size + 1; start ++){
				int end = start + size - 1;
				int mid = (start + end) / 2;
				ans = 0;
				for(int i = start; i <= end; i ++)
					ans += abs(a[i] - a[mid]);
				if(ans <= m){
					res = size;
					break;
				}
			}
		}
		cout << res << endl;
	}
	
	return 0;
}
