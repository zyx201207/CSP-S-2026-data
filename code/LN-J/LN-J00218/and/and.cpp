#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200010];
bool vis[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=30;i>=0;i--)
	{
		int p=0;
		for(int j=1;j<=n;j++)
		{
			if((a[j] & (1<<i)) && !vis[j])
			{
				p++;
			}
		}
		if(p>=m)
		{
			ans+=1<<i;
			for(int j=1;j<=n;j++)
			{
				if(!(a[j] & (1<<i)))
				{
					vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
