#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int MAXN = 5e5+5;
int n, m, a[MAXN], s[MAXN];
signed main(){
	cin.tie(nullptr); ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)  cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)  s[i] = s[i-1] + a[i];
	int ans = 0;
	for(int i=1;i<=n;i++){
		int l = 1, r = i, mid;
		//cout << i << " " << a[i] << ": \n";
		while(l < r){
			mid = (l + r) >> 1;
			//cout << mid << " " << s[i] << " " << s[mid-1] << endl;
			if(a[i] * (i-mid+1) - (s[i]-s[mid-1]) > m)  l = mid+1;
			else  r = mid;
		}
		//cout << "ans: " << l << endl;
		ans = max(ans, i-l+1);
	}
	cout << ans << endl;
	return 0;
}
