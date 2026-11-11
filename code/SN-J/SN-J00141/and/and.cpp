#include <bits/stdc++.h>
using namespace std;
int a[10000005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 3;i<=m+2;i++)
	{
		cout<<a[i] << " ";
	}
	return 0;
}
