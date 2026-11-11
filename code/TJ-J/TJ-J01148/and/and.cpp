#include <bits/stdc++.h>
using namespace std;
long long a[100000000005];
int maxand = -1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] && a[i+1] > maxand)
		maxand == a[i] && a[i+1];
	}
	cout << maxand;
	return 0;
}
