#include<bits/stdc++.h>
using namespace std;
int a[500000];
int cmd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmd);
	long long b;
	for(int i=2;i<=m;i++)
	{
		a[1]=a[1]&a[i];
	}
	cout<<a[1];
	return 0;
}
