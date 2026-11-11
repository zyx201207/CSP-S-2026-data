#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[200050];
bool vis[200050];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool ok=0;
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((a[j]>>i)&1)
			{
				if(ok&&vis[j])cnt++;
				else if(!ok)
				{
					cnt++;
					vis[j]=1;
				}
			}
			else vis[j]=0;
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			ok=1;
		}
		else if(!ok)
		{
			memset(vis,0,sizeof vis);
		}
	}
	cout<<ans;
	return 0;
}
