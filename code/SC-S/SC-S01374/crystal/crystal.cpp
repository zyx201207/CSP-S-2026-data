#include<bits/stdc++.h>
using namespace std;
inline long long read();
int n;
long long m;
long long a[500005];
long long d[500005];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i ++){
		a[i] = read();
	}
	stable_sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		d[i] = a[i] - a[i - 1];
		//cout << d[i] << ' ';
	}
	//cout << '\n';
	/*int mx = 0;
	for(int i = 2; i <= n; i ++){
		int cnt = 0, ans = 0;
		while(cnt <= m && ans + i - 1 <= n){
			ans ++;
			cnt += ans * d[ans + i - 1];
		}
		mx = max(ans, mx);
	}
	cout << mx;*/
	int l = 2, r = 2;
	long long cnt = d[2];
	int ans = 0;
	while(l <= r && r <= n){
		//cout << l << ' ' << r << ' ' << cnt << '\n';
		if(cnt <= m){
			ans = max(ans, r - l + 2);
			r ++;
			cnt += d[r] * (r - l + 1);
		}
		else{
			cnt -= a[r] - a[l - 1];
			l ++;
		}
	}
	cout << ans;
	return 0;
}
inline long long read(){
	long long f = 0, s = 1; char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	s = -1;
		c = getchar();
	}
	while(isdigit(c)){
		f = (f << 3) + (f << 1) + (c ^ 48);
		c = getchar();
	}
	return f * s;
}