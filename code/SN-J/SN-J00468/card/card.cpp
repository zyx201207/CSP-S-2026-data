#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050],b[500050],ans[500050];
int cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++)
		{
			bool ok=0;
			int now=0;
			for(int k=1;k<=cnt;k++)
			{
				if(a[j]==b[k])ok=1;
				if(ok)
				{
					now++;
				}
			}
			cnt-=now;
			b[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
