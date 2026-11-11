#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M],cnt[M],id[M],vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]=0; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]>1)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(vis[k]==1) continue;
					cnt[a[k]]--;
					vis[k]=1;
					if(a[k]==a[j]) break;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=min(1,cnt[j]);
			//cout<<i<<" "<<j<<" "<<cnt[j]<<"\n";
			cnt[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
