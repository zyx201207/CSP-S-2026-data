//王子政 SN-J00825 西安市益新中学
#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[n];
}
