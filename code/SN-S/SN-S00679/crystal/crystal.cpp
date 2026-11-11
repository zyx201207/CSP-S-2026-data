#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], maxn, ls;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long p = 1;
	ls = m;
	for(long long i = 1; i <= n - maxn; i ++){
		ls += a[p] - a[i];
		while(ls >= 0){
			while(a[p] == a[p + 1] && p + 1 <= n) p ++;
			long long c = a[p + 1] - a[p];
			long long e = p - i + 1;
			long long d = e * c;
			if(ls >= d){
				ls -= d;
				p ++;
			}
			else{
				break;
			}
		}
		long long f = p - i + 1;
		maxn = max(f, maxn);
	}
	cout << maxn;
	return 0;
}
