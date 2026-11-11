#include<bits/stdc++.h>
using namespace std;
long long a[500005][2],s[500005],n,m,d[50005],k,l;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		a[i][1]=s[a[i][0]];
		s[a[i][0]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		s[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
		
			if(a[j][1]>=i)
			{
				while(d[l]!=a[j][0]&&l>0)
				{
					l--;
				}
			}
			else
			{
				d[++l]=a[j][0];
			}
		}
		for(int j=1;j<=l;j++)
		{
			s[d[j]]++;
		l=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
}
