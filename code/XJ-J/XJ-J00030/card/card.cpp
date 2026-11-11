#include<iostream>
using namespace std;
int a[200005],flag[200005],sum[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m,T,i,j,s=-1,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		flag[i]=0;
		sum[i]=0;
	} 
	T=n;
	while(T--)
	{
		s++;
		for(i=1+s;i<=n;i++)
		{
			for(j=i;j>=1+s;j--)
			{
				if(i!=j&&a[j]==a[i]&&flag[j]!=1&&flag[i]!=1)
				{
					for(k=i;k<j;k++)
					{
						flag[k]=1;
					}
					break;
				}
			}
		}
		for(i=1+s;i<=n;i++)
		{
			if(flag[i]==0)
			{
				sum[a[i]]++;
			}
		}
		for(i=1;i<=n;i++)
		{
			flag[i]==0;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0; 
}
