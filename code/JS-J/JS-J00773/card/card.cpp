#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,b[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			memset(b,0,sizeof(b));
			int tot=i,cnt=i;
			while(cnt<=n)
			{
				for(int j=i;j<tot;j++)
				{
					if(b[j]==a[cnt])
					{
						tot=j;
						break;
					}
				}
				b[tot++]=a[cnt++];
			}
			for(int j=i;j<tot;j++)
			{
				ans[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else
	{
		for(int i=2;i<=n+1;i++)
		{
			if(a[i]!=a[i-1]) b[a[i-1]]=i-1;
		}
		for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	}
	return 0;
}
