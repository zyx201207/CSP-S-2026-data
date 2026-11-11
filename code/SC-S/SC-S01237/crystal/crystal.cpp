#include <bits/stdc++.h>
using namespace std;
#define int long long
const int jia = 1e12;
int n,m,a[500005],s[500005],ans;
int js1(int x){
	int k = m,i;
	for (i = x;i >= 1;i--){
		k -= a[x] - a[i];
		if (k < 0){
			break;
		}
	}
	return x - i;
}
int js2(int x){
	int l = 1,r = x,cnt = x;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (a[x] * (x - mid + 1) - (s[x] - s[mid - 1]) > m){
			l = mid + 1;
		}else{
			cnt = min(cnt,mid);
			r = mid - 1;
		}
	}
	return x - cnt + 1;
}
void solve1(){
	for (int i = 1;i <= n;i++){
		ans = max(ans,js1(i));
	}
	cout << ans << "\n";
}
void solve2(){
	for (int i = 1;i <= n;i++){
		ans = max(ans,js2(i));
	}
	cout << ans << "\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		a[i] += jia;
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1,a + n + 1);
	if (n <= 5000){
		solve1();
		return 0;
	}
	if (a[2] - a[1] != a[3] - a[2]){
		solve2();
		return 0;
	}
	int cnt = a[2] - a[1];
	int zh = m / cnt,sum = 0,i;
	for (i = 1;i <= n;i++){
		sum += i;
		if (sum > zh){
			break;
		}
	}
	cout << i << "\n";
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

7 6
1 2 2 4 5 8 8
*/