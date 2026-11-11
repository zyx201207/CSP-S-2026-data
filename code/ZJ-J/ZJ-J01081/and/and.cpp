#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	cout<<a[m];
	return 0;
}
