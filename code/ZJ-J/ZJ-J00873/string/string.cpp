#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int maxn=2e5;
int n,cn=1,ans;
char a[maxn];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1; i<=n; i++) {
		int t;
		char c;
		cin >> t >> c;
		for (int i=cn; i<=cn+t-1; i++) a[i] = c;
		cn+=t;
	}
	cn--;
	if (n==1) {
		cout << "0";
		return 0;
	}
	bool f=1;
	for (int i=1; i<=cn/2+1; i++) {
		if (a[i]!=a[cn-i+1]) {
			ans++;
			f=0;
		}
	}
	if (f) {
		cout << "0";
		return 0;
	}
	cout << ans;
	return 0;
}