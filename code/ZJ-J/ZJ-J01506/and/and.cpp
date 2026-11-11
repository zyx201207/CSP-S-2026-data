#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	long long max1=0;
	int a[200001]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int hh=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2!=0)
		{
			max1=a[i];
			hh=i;
			break;
		}
	}
	m+=hh-1;
	for(int i=hh+1;i<=m;i++)
	{
		max1=max1&a[i];
	}
	cout<<max1;
	return 0;
} 
