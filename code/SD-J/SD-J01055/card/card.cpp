#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int mp[1000005];
int sum[1000005];
int f[1000005],r;
int num=0;
int find(int x)
{
	for(int i=0;i<=r-1;i++)
	{
		if(x==f[i])
		{
			num=i;
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=500)
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=k;i<=n;i++)
			{
				num=0;
				if(find(a[i])==1&&r!=0)
				{
					r=num;
				}
				f[r++]=a[i];
				
			}
			for(int ii=0;ii<r;ii++)
				{
					mp[f[ii]]++;
				}
				for(int j=0;j<r;j++)
				{
					f[j]=0;
				} 
				r=0;
		}
	
		for(int i=1;i<=m;i++)
		{
			cout<<mp[i]<<" ";
		}
		return 0;
	}
	else if(m==1)
	{
		cout<<n;
		return 0;	
	}
	else if(m==2)
	{
		if(a[n]==1) cout<<n<<" "<<1;
		else cout<<1<<" "<<n;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			mp[a[i]]++;
		}
		
		for(int i=1;i<=m;i++)
		{
			sum[i]=sum[i-1]+mp[i];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<sum[i]<<" ";
		}
		return 0;
	}
	return 0;
	
}
