#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000001],b[1000001],c[1000001];
void dg(int l,int r)
{
	b[a[l]]=1;
	b[a[r]]=1;
	if(a[l]!=a[r]&&l-r>=1)
	{
		dg(l+1,r-1);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			b[j]=0;
		}
		dg(i,n);
		for(int j=1;j<=k;j++)
		{
			if(b[j]==1)
			{
				c[j]++;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}


