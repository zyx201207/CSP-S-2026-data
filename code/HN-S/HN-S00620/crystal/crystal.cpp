#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, mx;
ll m, a[N], s[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		if(a[i + 1] == a[i]) continue;
		int l = 1, r = i, ans = -1;
		while(l <= r){
			int mid = l + r >> 1;
			ll w1 = (i - mid + 1) * a[i];
			ll w2 = s[i] - s[mid - 1];
			if(w1 - w2 <= m) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		mx = max(mx, i - ans + 1);
	}
	cout << mx;
	return 0;
} 
