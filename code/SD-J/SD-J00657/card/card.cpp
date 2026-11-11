#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001];
void f(int i)
{
	long long k=0,p[m]={},l[m]={},c[n]={};
		for(int j=i;j<=n;j++)
		{
			c[++k]=a[j];
			p[a[j]]++;
			if(p[a[j]]==2)
			{
				
				for(int h=l[a[j]];h<k;h++)
				{
					if(p[c[h]]==1)
					{
						p[c[h]]=0;
					}
					c[h]=0;
				}
				p[a[j]]=1;
			}
			l[a[j]]=k;
		}
		for(int j=1;j<=k;j++)
		{
			b[c[j]]++;
		}
		return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(int i=1;i<=n;i++)
	{
		f(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 
