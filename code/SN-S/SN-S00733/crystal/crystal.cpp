#include<bits/stdc++.h>
using namespace std;
long long x, n, m, ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>> n >> m;
	vector<long long> a;
	for (int i = 1; i <= n; i++){
		cin>> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; i++){
		if (m < ((a[i + 1] - a[i]) * i)){
			break;
		}
		m =  m - (a[i + 1] - a[i]) * i;
		ans = i + 1;
	}
	cout<< ans + 1;
	return 0;
} 
