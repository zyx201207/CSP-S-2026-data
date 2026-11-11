#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],b[500001],pos[300001],used[300001],ans[300001];
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
		memset(used,0,sizeof(used));
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
			if(used[a[j]]!=0)
			{
				for(int f=pos[a[j]];f<=j-1;f++)
				{
					used[b[f]]--;
					b[f]=0;
					if(pos[a[f]]==f)pos[a[f]]==0;
				}
			}
			pos[a[j]]=j;
			used[a[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(used[j]!=0)
			{
				ans[j]++;
			}
			cout<<used[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}