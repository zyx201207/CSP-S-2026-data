#include<bits/stdc++.h>
#include<map>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int mp[300005];
int ans[300005];
bool vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
	{
		memset(mp,0,sizeof mp);
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++)
		{
			mp[a[j]]++;
			if(mp[a[j]]>1)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(!vis[k])
					{
						vis[k]=1;
						mp[a[k]]--;
						if(a[k]==a[j])
							break;
					}
				}
				mp[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++)
			ans[i]+=mp[i];
			
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
} 
