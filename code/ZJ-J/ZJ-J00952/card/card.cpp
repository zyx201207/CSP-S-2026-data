#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[500005],ans[300005];
struct S{
	int l,r;
}f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				k++;
				f[k].l=i;
				f[k].r=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int flag=i;
		for(int j=1;j<=k;j++)
		{
			if(f[j].l>=flag)
			{
				for(int l=flag;l<=f[j].l-1;l++)
				{
					ans[a[l]]++;
				}	
				flag=f[j].r;
			}
		}
		for(int j=flag;j<=n;j++)
		{
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";	
	}
	return 0;
}