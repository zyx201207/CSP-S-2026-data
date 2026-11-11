#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int sum=a[1];
	for(int i=2;i<=m;i++)
	{
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
