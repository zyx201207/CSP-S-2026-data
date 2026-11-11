#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+1145;
int n, m, a[N];
main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1, a+n+1);
	int val = 0;
	int ans = 1;
	int l = 1;
	for(int r = 1;r <= n;r++){
		val += (r - l) * (a[r] - a[r-1]);
		while(val>m){
			val-=a[r]-a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
