#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n.m,a[100];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a;
	}
	sort(a,a+n,cmp);
	int x=a[0]^a[1],y=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<=m;j++)
		{
			
			y=y+a[i]^a[i+1];
		}
		x=max(x,y);
	}
	cout<<x;
	return 0;
}	
