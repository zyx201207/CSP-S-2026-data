#include <bits/stdc++.h>
#define int long long
using namespace std;
int  n,m;
int a[500005];
int cnt[500005];
int f[100005];
int b[15];
int ans[15];
stack <int> q;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cnt[0]=1;
	int cntt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
		if(a[i]!=a[i-1])
		{
			cnt[i]=cnt[i-1]+1;
		}
		else
			cnt[i]=cnt[i-1];
		if(a[i]>=a[i-1])
		{
			cntt++;
		}
	}
	if(cntt==n)
	{
		// cout<<1<<endl;
		vector <int> id;
		for(int i=1;i<=1e5;i++)
		{
			if(f[i]!=0)
			id.push_back(i);
		}
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			int num=id[i-1];
			cout<<sum+f[num]<<" ";
			sum+=f[num];

		}	
		return 0;
	}
	if(n<=10 && m<=10)
	{
		// cout<<1<<endl;
		
		for(int i=1;i<=n;i++)
		{
			// for(int j=1;j<=m;j++)
			// {
			// 	cout<<ans[j]<<" ";
			// }
			// cout<<endl;
			for(int j=1;j<=n;j++)
			{
				b[j]=0;
			}
			for(int j=i;j<=n;j++)
			{
				for(int k=1;k<=j-1;k++)
				{
					if(b[k] && a[k]==a[j])
					{
						for(int l=k;l<j;l++)
						{
							b[l]=0;
						}
					}
				}
				b[j]=1;
			}
			for(int j=1;j<=n;j++)
			{
				if(b[j])
				{
					ans[a[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
}