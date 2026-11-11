#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, ans;
int a[N], c[N], s1[N], s2[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i < n; i++) c[i] = a[i + 1] - a[i];
	for(int i = n - 1; i; i--) s1[i] = s1[i + 1] + c[i];
	for(int i = n - 1; i; i--) s2[i] = s2[i + 1] + s1[i];
	for(int i = 2; i <= n; i++){
		int l = 1, r = i;
		while(l < r){
			int mid = l + r >> 1;
			if(s2[mid] - s2[i] - s1[i] * (i - mid) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
