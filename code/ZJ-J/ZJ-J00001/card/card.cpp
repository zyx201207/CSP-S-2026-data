#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
unordered_map<int,int>mp;
bool flag=false;
int tot[N];
unordered_map<int,int> ans;
signed main()
{//score 12
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=a[i-1])
		{
			mp[a[i]]++;
		}
		else
		{
			flag=true;
		}
	}
	if(flag==false)
	{
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			sum+=mp[i];
			cout<<sum<<' ';
		}		
	}
	else
	{
		int nums=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				nums=0;
				for(int k=1;k<=nums;k++)
				{
					if(tot[k]==a[j])
					{
						for(int l=k;k<=nums;k++)
						{
							tot[l]=0;
						}
					}
				}
				tot[++nums]=a[j];
			}
			for(int j=1;j<=n;j++)
			{
				if(tot[j]!=0)
				{
					ans[tot[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
