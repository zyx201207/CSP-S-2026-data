#include<bits/stdc++.h>
using namespace std;

int ans[300000+10],a[500000+10],w[300000+10],li[300000+10],cnt=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int _=1;_<=n;_++)
	{
		for(int i=_;i<=n;i++)
		{
			if(w[a[i]]==0)
			{
				li[++cnt]=a[i];
				w[a[i]]=cnt;
			}
			else
			{
				for(int j=w[a[i]]+1;j<=cnt;j++)
				{
					w[li[j]]=0;
				}
				cnt=w[a[i]];
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			ans[li[i]]++;
		}
		memset(li,0,sizeof(li));
		memset(w,0,sizeof(w));
		cnt=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
