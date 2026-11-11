#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j,s=0,a[10000];
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	if(m==1)
	{
		cout<<a[n];
		return 0;	
	}
	if(m==n)
	{
		cout<<1;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j]==a[i])
			{
				cout<<a[i];
				return 0;
			}
		}
	}
	return 0;
}