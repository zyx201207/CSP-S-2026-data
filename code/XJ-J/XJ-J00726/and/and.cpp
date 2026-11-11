#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL n,m;
LL a[200005];
LL ans;

bool cmp(LL x,LL y) {
	return x>y;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(LL i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(LL i=2; i<=m; i++) {
		ans=ans&a[i];
	}
	cout << ans << endl;
	return 0;
}