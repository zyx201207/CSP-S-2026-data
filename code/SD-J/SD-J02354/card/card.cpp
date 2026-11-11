#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int ans[300005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int k=i;
		for(int j=i;j<=n;j++)
		{
			b[a[j]]++;
			if(b[a[j]]==2)
			{
				for(;k<=j;k++)
				{
					if(b[a[k]]>=1)
					{
						b[a[k]]--;
					}
				} 
				k=j;
			}
			cout<<b[i]<<" ";
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]>=1)
			{
				ans[i]++;
			}
		}
		cout<<endl;
		for(int i=1;i<=m;i++)
		{
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
