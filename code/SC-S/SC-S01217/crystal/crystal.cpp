#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,ans=0,jl[500005],num=0,sum=0,top=1,k=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		jl[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++)
	{
		num=0;
		sum=0;
		top=1;
		k=1;
		while(1)
		{
			sum+=(jl[i+num]*k);
			if((i+num)==n||sum>m)
			{
				break;
			}
			num++;
			top++;
			k++;
		}
		ans=max(ans,top);
	}
	cout<<ans;
	return 0;
} 