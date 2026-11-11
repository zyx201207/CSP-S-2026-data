#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005]={0},b[500005]={0},c[300005]={0},number[300005]={0};
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)//i
	{
		int o=1;
		for(int j=i;j<=n;j++)//j
		{
			int r=0;
			for(int k=1;k<=o;k++)
			{
				if(r==1)
				{
					c[b[k]]--;
					b[k]=0;
				}
				else if(a[i]==b[k])
				{
					r=1;
					c[b[k]]--;
					b[k]=0;
				}
			}
			b[o]=a[i];
			c[a[i]]++;
			o++;
		}
		for(int j=1;j<=m;j++)
		{
			if(c[j]!=0)
			{
				number[j]++;
			}
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<number[i]<<" ";
	}
	return 0;
}