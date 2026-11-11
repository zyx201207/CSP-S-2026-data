#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500005], b[500005], ans = 0, c[500005];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a, a + n);
	b[0] = 0;
	for(long long i = 1;i < n;i++){
		b[i] = a[i] - a[i - 1];
	}
	long long t = 1, q = m;
	for(long long i = 0;i < n;i++){
		while(q >= 0 && i + t <= n){
			q -= t * b[i+t];
			t++;
		}
		c[i] = t-1;
		if(i + t > n){
			break;
		}
		q += (a[i+t-1] - a[i]);
		t--;
	}
	for(int i = 0;i < n;i++){
		if(c[i] > ans){
			ans = c[i];
		}
	}
	cout << ans << endl;
	return 0;
}
