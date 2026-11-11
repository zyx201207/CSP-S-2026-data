#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[200100],a[200100],vis[200100],cnt[32],ans[200100];
signed main(void)
{
	freopen("card.in","r",stdin);
	freopen("card.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=1;j<=m;j++) cnt[j]=0;
        for(int j=1;j<=n;j++) s[j]=0;
		for(int j=1+i-1;j<=n;j++)
		{
			if(!vis[a[j]] || vis[a[j]]>k) 
			{
				k=vis[a[j]];
			}
			else
			{
				vis[a[j]]=k;
			}
			s[k]=a[j];
			k++;
		}
		for(int j=1;j<=k;j++)
		{
			if(!cnt[s[j]])
			{
				cnt[s[j]]=1;
			    ans[s[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
			