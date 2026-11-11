#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],z=0,ret[300005],b[500005],t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
		{
			t[l]=0;
		}
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
			t[a[j]]++;
			if(t[a[j]]>1)
			{
				for(int k=i;k<=j;k++)
				{
					if(z==0 && b[k]==a[j])
					{
						z=1;
						t[b[k]]--;
						b[k]=0;
					}
					else if(z==1 && b[k]!=a[j])
					{
						t[b[k]]--;
						b[k]=0;
					}
					else if(z==1 && b[k]==a[j])
					{
						z=0;
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j]>0)
			{
				ret[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ret[i]<<" ";
	}
	return 0;
}  
