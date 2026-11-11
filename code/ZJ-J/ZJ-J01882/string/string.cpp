#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	long long cnt = 0;
	int l = 1, r = n;
	while(l < r){
		int mn = min(a[l], a[r]);
		if(c[l] != c[r]) cnt += mn;
		a[l] -= mn;
		a[r] -= mn;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout << cnt << '\n';
	return 0;
}
