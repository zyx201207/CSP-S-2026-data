#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[355555],ans,st[355555],used[355555];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st[i]=1;
	}
	for(int k=30;k>=0;k--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(st[i])
			{
				if((a[i]>>k)&1)
				{
					cnt++;
					used[i]=1;
				}
			}
			
		}
		if(cnt>=m)
		{
			ans+=1ll<<k;
			for(int i=1;i<=n;i++)
			{
				if(used[i])st[i]=1;
				else st[i]=0;
			
			}
		}
		for(int i=1;i<=n;i++)used[i]=0;
		
	}
	cout<<ans;
	return 0;
}
