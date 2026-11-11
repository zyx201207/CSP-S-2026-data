#include<bits/stdc++.h>
using namespace std;

int a[200010];
char c[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c",&a[i],&c[i]);
	
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(a[l]!=a[r])
		{
			if(c[l]!=c[r])
			{
				int mn=min(a[l],a[r]);
				int mx=max(a[l],a[r]);
				ans+=mn;
				if(mx==a[l])
				{
					a[l]-=mn;
					r--;
				}
				else
				{
					a[r]-=mn;
					l++;
				}
			}
			else
			{
				int mn=min(a[l],a[r]);
				int mx=max(a[l],a[r]);
				
				if(mx==a[l])
				{
					a[l]-=mn;
					r--;
				}
				else
				{
					a[r]-=mn;
					l++;
				}
			}
		}
		else
		{
			if(c[l]!=c[r]) ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	
	
	
	return 0;
}
