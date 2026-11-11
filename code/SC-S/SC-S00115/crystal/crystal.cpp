#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
int n;
ll m, a[maxn],sum[maxn];
bool check(int l, int r){
	ll x = (sum[r] - sum[l - 1]) - (a[r] - a[l - 1]) * l;
	return x <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * i;
	}
	ll ans = 0;
	for (int l = 1;l <= n;l ++){
		int L = l ,R = n,mid,r;
		while (L <= R){
			mid = L + R >> 1;
			if (check(l,mid)){
				L = mid + 1;
				r = mid;
			}else{
				R = mid - 1;
			}
		}
		ans = max(ans,r - l + 1);
	}
	cout << ans << endl;
	return 0;
} 