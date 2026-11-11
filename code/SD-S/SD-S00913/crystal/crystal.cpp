#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
long long a[N + 5];
long long n, m;
bool chicken(long long x){
	long long res = 0, cnt = 0;
	for(int i = 1;i <= x;i++){
		cnt += a[x] - a[i];
	}
	res = cnt;
	for(int i = 2;i <= n - x + 1;i++){
		cnt = cnt - (a[i - 2 + x] - a[i - 1]);
		cnt = cnt + (a[i - 1 + x] - a[i - 2 + x]) * (x - 1);
		res = min(res, cnt);
	}
	if(res <= m) return 1;
	else return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long l = 1, ct = 1;
	for(int i = 2;i <= n;i++){
		if(a[i] == a[i - 1]) ct++;
		else ct = 1;
		l = max(l, ct);
	}
	l = max(l, ct);
	long long r = n + 1;
	while(l < r - 1){
		long long mid = (l + r) / 2;
		if(chicken(mid) == 1) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}
