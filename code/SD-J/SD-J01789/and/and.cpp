#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	int x = a[1];
	for(int i = 2;i <= m;i ++){
		x &= a[i];
	}
	cout << x;
	return 0;
}
