#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],id[N],cnt[N];
bool d[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(id,0,sizeof(id));
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++)
		{
			if(id[a[j]]==0)
			{
				id[a[j]]=j;
				d[j]=1;
				cnt[a[j]]++;
			}
			else
			{
				for(int k=id[a[j]]+1;k<j;k++)
				{
					if(d[k]==1)
					{
						d[k]=0;
						id[a[k]]=0;
						cnt[a[k]]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
