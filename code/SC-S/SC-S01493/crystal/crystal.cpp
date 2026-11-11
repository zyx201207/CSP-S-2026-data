#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,m, ans = 1;
int a[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	int  l = 1, r = 1;
	int k = 0;
	for(int r = 2; r <= n; r++){
		k += (a[r] - a[r - 1]) * (r - l);
		while(k > m){
			k -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}