//钟林希 西安翱翔中学 SN-J00675 
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[300050],vis[300050],a[500050],viss[300050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			viss[a[j]]++;
			if(viss[a[j]]==2)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(vis[k]==-1)continue;
					vis[k]=-1;
					viss[a[k]]--;
					if(a[k]==a[j])break;
				}
				viss[a[j]]=1;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(vis[j]!=-1)
			{
				cnt[a[j]]++;
			}
			viss[a[j]]=0;
			vis[j]=0;
		}
	}
	for(int i=1;i<m;i++)printf("%d ",cnt[i]);
	printf("%d",cnt[m]);
	return 0;
}
