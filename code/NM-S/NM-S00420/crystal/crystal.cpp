#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
double a[N], d[N], sum, s[N];
long long m;
double cnt, mi = INT_MAX, minn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		cnt += a[i];
		s[i] = a[i] - a[i - 1];
	}
	bool ok = 1;
	for (int i = 2; i < n; i ++){
		if (s[i] != s[i + 1]) ok = 0;
	}
	if (ok == 1){
		cout << floor (m / s[2]);
	}
	else {
		cnt /= n;
	for (int i = 1; i <= n; i ++){
		if (abs(a[i] - cnt) < mi){
			minn = a[i];
			mi = abs(a[i] - cnt);
		}
	}
	for (int i = 1; i <= n; i ++){
		d[i] = abs (minn - a[i]);
	}
	sort (d + 1, d + n + 1);
	for (int i = 1; i <= n; i ++){
		if (m - d[i] >= 0){
			m -= d[i];
			sum ++;
		}
	}
	cout << sum;
	}
	return 0;
} 
