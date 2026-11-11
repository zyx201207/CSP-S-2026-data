#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], ans = 1, pre[N];
int co(int pos){
	int x = a[pos];
	int cnt = m, sum = 0;
	for(int i = pos;i >= 1;i --){
		if(abs(x - a[i]) > cnt) break;
		sum ++;
		cnt -= abs(x - a[i]);		
	}
	return sum;
}
bool check(int x){
	int pos = upper_bound(a + 1, a + 1 + n, x) - a;
	pos -= 1;
	int cnt = m, sum = 0;
	for(int i = pos;i >= 1;i --){
		if(x - a[i] > cnt) break;
		cnt += abs(x - a[i]);		
	}
	if(sum >= ans) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(n <= 5000){
		for(int i = 1;i <= n;i ++){
			ans = max(ans, co(i));
		}
		cout << ans;
		return 0;
	}
	else{
		for(int i = 1;i <= n;i ++){
			pre[i] = pre[i - 1] + a[i];
		}
		int l = 1, r = 1;
		while(l <= n && r <= l){
			int g = a[l] * (l - r + 1);
			int c = g - (pre[l] - pre[r - 1]);
			if(c <= m) {
				ans = max(ans, l - r + 1);
				l ++;
			}else{
				r ++;
			}
			//cout << r << " " << l << "\n";
		}
		cout << ans;
	}
	//cout << ans << " " << l << " " << r << "\n";
	return 0;
}