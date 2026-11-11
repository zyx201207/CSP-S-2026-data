#include<bits/stdc++.h>
using namespace std;
int x,m=1,i,j,n,a[10000005],b[10000005],all;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(i=1;i<=m;i++)
	{
		b[i]=a[i];
	}
	all=a[1];
	for(i=2;i<=m;i++)
	{
		x=all&b[i];
		all=x;
	}
	cout<<all<<endl;
	return 0;
}