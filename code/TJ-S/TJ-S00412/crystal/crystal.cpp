#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans;
int a[500005], sum[500005];
bool check(int l, int r){
	int cnt = sum[r] - sum[l - 1];
	int cnt2 = (r - l + (int)1) * a[r];
	return ((cnt2 - cnt) <= m ? true : false);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i++){//枚举每个点作为右端点也就是最大值 
		int l = 1, r = i;
		while(l <= r){
			int mid = l + (r - l) / 2;
			if(check(mid, i))
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, (i - l + 1));
	}
	cout << ans;
	return 0;
}
