#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,a[N],vis[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=INT_MIN,sum=1;
	for(int i=1;i<=n;i++)
	{
		sum=1;
		int x=m;
		for(int j=i-1;j>=1;j--)
		{
			if(x-(a[i]-a[j])>=0)
			{
				if(a[j]<a[i])
				{
					sum++;
					x-=(a[i]-a[j]);
				}
				else
				{
					sum++;
				}
			}
			else
			{
				break;
			}
		} 
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;	
} 
