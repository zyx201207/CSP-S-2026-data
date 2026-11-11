#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0,an;
	int a[200005]={};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	an=a[0];
	for(int i=1;i<n;i++)
	{
		an=an&a[i];
	}
	if(m==1)
	{
		cout<<mx;
	}
	else if(m==n)
	{
		cout<<an;
	}
	else if(m==2)
	{
		mx=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				an=a[i]&a[j];
				mx=max(mx,an);
			}
		}
		cout<<mx;
	}
	return 0;
}
