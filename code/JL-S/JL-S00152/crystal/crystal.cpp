#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long a[500001], Max = 1, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int p = n, q;
	while(p > 0){
		q = n;
		long long k = m, sum = 1;
		while(k > 0 && q > 0){
			if(a[q] <= a[p]){
				if((a[p] - a[q]) > k) break;
				else k -= (a[p]-a[q]);
				if(p != q) sum++;
			}
			q--;
		}
		if(Max < sum){
			
			Max = sum;
		}
		p--;
	}
	cout << Max;
}
