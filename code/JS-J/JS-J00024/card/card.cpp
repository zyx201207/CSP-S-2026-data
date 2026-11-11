#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[500010];
int main()
{
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)//card
		{
			for(int k=i;k<=j;k++)//chongfu
			if(a[j]==a[k])
			{
				for(int l=k+1;l<=j;l++)a[l]=0;
				break;
			}
		}
		for(int j=i;j<=n;j++)
		if(a[j])b[a[j]]++;
		for(int j=1;j<=n;j++)a[j]=c[j];
	}
	for(int i=1;i<=300000;i++)
	if(b[i])cout<<b[i]<<' ';
	return 0;
}
