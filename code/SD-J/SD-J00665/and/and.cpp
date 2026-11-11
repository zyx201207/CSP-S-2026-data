#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int ans;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	ans=a[1];
	for (int i=2;i<=n;i++)
	{
		ans=ans&a[i];
	}
	cout <<ans;
	return 0;
}
