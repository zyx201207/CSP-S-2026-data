#include<bits/stdc++.h>
using namespace std;
long long a[10001],n,m,c,b[10001],s=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	s=0;
	int x=1,l=0;
	for(int i=1;i<=m;i++)
	{
		a[x]++;
		if(a[x]==a[n/2+1])
		{
			
			b[l]=a[x]; 
			x++;
			l++;
		}
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(b[1]==a[i])
		{
			l++;
		}
	}
	cout<<l;
	return 0;
} 
