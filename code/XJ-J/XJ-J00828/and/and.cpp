#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	int a[1001];
	int maxand = 0;
	int b = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
		for(int k = 1;k <= n;k++){
			b = a[k] & a[k+1];
			maxand = max(maxand, b);
		}
	cout << maxand;
	return 0;
}