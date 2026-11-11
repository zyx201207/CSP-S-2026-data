#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans[500010],c;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		b[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=a[i+1])
		{
			b[a[i]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		c+=b[i];
		c--;
	}
	for(int k=0;k<m;k++)
	{
		for(int i=k;i<n;i++)
		{
			if(b[i]%2!=0)
			{
				ans[i]++;
			}
		}
	}
	for(int i=0;i<n-c;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
