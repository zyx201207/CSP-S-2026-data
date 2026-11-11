#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 500005;
int n, m, ans;
LL a[N], s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++){
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = 1;
	while(l <= r && r <= n){
		LL sum = a[r] * (r - l) - s[r - 1] + s[l - 1];
		if(sum <= m){
			ans = max(ans, r - l + 1);
			r++;
		}else{
			l++;
		}
	}
	cout << ans;
	return 0;
}