#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << max(max((a[1] & a[2]),(a[1] & a[2])),a[2] & a[3]);
	return 0;
}