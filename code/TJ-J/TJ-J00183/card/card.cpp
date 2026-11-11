#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],b[500005],id,ans[300005];
bool sum[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int k=1;k<=n;k++)
	{
		id=0;
		memset(sum,0,sizeof(sum));
		memset(cnt,0,sizeof(cnt));
		memset(b,0,sizeof(b));
		for(int i=k;i<=n;i++)
		{
			if(sum[a[i]]==0) b[++id]=a[i],cnt[a[i]]=id,sum[a[i]]=1;
			else
			{
				for(int j=cnt[a[i]]+1;j<=id;j++) sum[b[j]]=0;
				id=cnt[a[i]];
			}
		}
		for(int i=1;i<=id;i++) ans[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
 } 
