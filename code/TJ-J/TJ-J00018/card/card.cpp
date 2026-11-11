#include<bits/stdc++.h>
using namespace std;
int a[1000001],b1[1000001],c1[1000001],x=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.in","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		x=a[i]&a[i-1];
	}
	cout<<x;
	return 0;
}
