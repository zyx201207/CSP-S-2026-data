#include <bits/stdc++.h>
using namespace std;
const int N=2005;
struct node{
	int x;
	char v;
}a[N];
long long len=0,n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i].x >> a[i].v;
		len+=a[i].x;
	}
	if (n==1) {
		cout << 0;
	} else if (n==2) {
		if (a[1].v==a[2].v) cout << 0;
		else cout << min(a[1].x,a[2].x);
	}
	return 0;
}
