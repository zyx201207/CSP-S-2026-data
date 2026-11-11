#include <bits/stdc++.h>
using namespace std;
int n,m,sizeb;
int a[500005],b[500005],s[300005];
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
		for(int j=1;j<=sizeb;j++)
		{
			b[j]=0;
		}
		
		sizeb=0;
		
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=sizeb;k++)
			{
				if(b[k]==a[j])
				{
					for(int l=k;l<=sizeb;l++)
					{
						b[l]=0;
						sizeb--;
					}
				}
			
			}
				sizeb++;
				b[sizeb]=a[j];
		}
		for(int j=1;j<=sizeb;j++)
		{
			s[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' ';
	}
	return 0;
}