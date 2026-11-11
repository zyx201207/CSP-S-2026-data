#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","l",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+0,a+n+1);
	cout<<a[m];
	return 0;
}