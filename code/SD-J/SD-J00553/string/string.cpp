#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
char c[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int p=1,q=n;
	while(p<q) {
		if(c[p]==c[q]) {
			if(a[p]<a[q]) {
				p++;
				a[q]-=a[p-1];
			} else {
				q--;
				a[p]-=a[q+1];
			}
			continue;
		}
		if(a[p]<a[q]) {
			p++;
			a[q]-=a[p-1];
			m+=a[p-1];
		} else {
			q--;
			a[p]-=a[q+1];
			m+=a[q+1];
		}
	}
	cout<<m;

	return 0;
}
