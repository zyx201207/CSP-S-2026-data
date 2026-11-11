#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],sum[500001];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int maxx = 1;
	for (int i = 1;i <= n;i++){
		int l = 1,r = i,ans;
		while (l <= r){
			int mid = l + r >> 1;
			if (a[i] * mid - (sum[i] - sum[i - mid]) <= m){
				ans = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		maxx = max(maxx,ans);
	}
	cout << maxx;
	return 0;
} 
