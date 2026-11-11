#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cout<<i<<endl;
		for(int j=i;j<=n;j++)
		{
			int cnt[300010]={0},q=-1;
			for(int z=j;z<=n;z++)
				cnt[a[z]]++;
			for(int z=1;z<=m;z++)
				cout<<cnt[z]<<' ';
			cout<<endl;
			for(int z=j;z<=n;z++)
			{
				if(cnt[a[z]]>1)
					q=max(q,z);
			}
			for(int z=q;z<=n;z++)
				ans[a[z]]++;
		}		
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}