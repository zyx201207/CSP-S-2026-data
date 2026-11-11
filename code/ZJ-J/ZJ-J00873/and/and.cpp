#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;
const int maxn=2e5;
int n, m, maxx=-1;
int a[maxn];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) 
	    cin >> a[i];
	if(m==1) {
		sort(a+1, a+n+1);
		cout << a[n];
	}
	else if(m==2) {
		for (int i=1; i<=n; i++)
		    for (int j=1; j<=n; j++) {
		    	if (i==j) continue;
		    	maxx = max(maxx,(a[i]&a[j]));
			}
		cout << maxx;
	}
	else {
		sort(a+1,a+n+1);
		maxx = a[n-m+1];
		for (int i=n-m+2; i<=n; i++)
		    maxx = maxx&(a[i]);
		cout << maxx;
	}
	return 0;
}