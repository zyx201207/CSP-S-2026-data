#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m;
int a[N], d[N], h[N], sum[N], ans;
bool A = true, B = true;
typedef unsigned long long ull;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] != (i + 1)) A = false;
	}
	sort(a,a+n);
	int q = a[1] - a[0];
	for(int i = 1; i < n; i++)
		if(a[i] - a[i - 1] != q) 
			B = false;
	for(int i = 1; i < n; i++)
		d[i] = a[i] - a[0];
	for(int i = 1; i < n; i++) 
		h[i] = h[i - 1] + d[i];
	for(int i = 1; i < n; i++)
		sum[i] = i * d[i] - h[i - 1];
	if(n <= 1e4){
	for(int i = n - 1; i >= 1; i--){
		for(int j = 0; j < i; j++){
			if(m >= sum[i] - sum[j]){
				//cout << i - j + 1;
				ans = max(ans, i - j + 1);
			}
		}
	}
	cout << ans;
	return 0;
	}
	if(A){
		for(int i = 1; i <= n; i++)
			if(i * (i - 1) / 2 > m){
				cout << i - 1;
				return 0;
			}
	}
	if(B){
		for(int i = 1; i <= n; i++){
			ull cnt = q * i * (i - 1) / 2;
			if(cnt > (ull)m){
				cout << i - 1;
				return 0;
			}
		}
	}
	return 0;
}
