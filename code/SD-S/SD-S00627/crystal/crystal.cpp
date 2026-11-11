#include<bits/stdc++.h>
using namespace std;
int n, jmc = -114514;
long long zyn = -11111111111111;
long long m;  
vector<long long> v;
long long tyz = 0;
long long a[1145140], d[1145140], h[1145140];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		d[i - 1] = a[i] - a[i - 1];
	}
	int l = 1, r;
	for(int i = 1; i <= n; i++){
		l = i;
	for(r = i; r < n; r++){
		tyz += (d[r] * (r - l + 1));
		if(tyz > m){
		//	cout << a[l] << endl;
			jmc = max(jmc, r - l + 1);
			l = r;
			tyz = d[r] * (r - l + 1);
		} 
	}
	jmc = max(jmc, r - l + 1);
	tyz = 0;
}
	cout << jmc;
	return 0;
}

