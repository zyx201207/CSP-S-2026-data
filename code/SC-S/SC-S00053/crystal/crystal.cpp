#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++ i) sum[i] = sum[i - 1] + a[i];
	int res = 0;
	for(int p = 1; p <= n; ++ p){
		int l = 1, r = p - 1, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			ll val = (p - mid) * a[p] - (sum[p - 1] - sum[mid - 1]);
			if(val <= m){
				ans = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		res = max(res, p - ans + 1);
	}
	cout << res;
	
	return 0;
}