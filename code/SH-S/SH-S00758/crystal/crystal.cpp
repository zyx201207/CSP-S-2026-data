#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5+10;

int n;
ll m, a[N], p[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for (int i = 1; i <= n; i ++) {
		cin>>a[i];
	}
	
	sort(a+1, a+n+1);
	int end = 0, ans = 0;
	ll p = 0;
	for (int i = 1; i <= n; i ++) {
		p = p-a[end]+a[i-1];
		for (int j = end+1; ;j ++) {
			if (j==n+1) {
				ans = max(ans, n-i+1);
				i = n+1;
				break;
			}
			p += (a[j]-a[j-1])*(j-i);
			if (p > m) {
				end = j-1;
				p -= (a[j]-a[j-1])*(j-i);
				ans = max(ans, j-i);
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
//Oct31==Dec25?
