#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
long long n, m, a[N], sa[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) sa[i] = sa[i-1] + a[i];
	int maxn = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i-maxn; j > 0; j--) { //不必枚举不可能的情况 
			long long num = ( a[i] * (i-j+1) ) - (sa[i] - sa[j-1]);
			if (num > m) break; 
			maxn = max(maxn,i-j+1);
		}
	}
	cout << maxn << "\n";
	return 0;
}
//Greedy! 
//checked
