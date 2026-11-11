#include<bits/stdc++.h>
using namespace std;
int n, l, r;
long long ans;
vector<long long> a;
vector<char> b;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	r = n - 1;
	a.resize(n);
	b.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	while(l < r){
		int mi = min(a[l], a[r]);
		if(b[l] != b[r]){
			ans += mi;
		}
		a[l] -= mi;
		a[r] -= mi;
		if(a[l] == 0){
			l++;
		}
		if(a[r] == 0){
			r--;
		}
	}
	cout << ans << endl;
	return 0;
} 
