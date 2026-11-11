#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300001],ans[500005],cnt,ne[500005];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int idx=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i&&idx==0) idx=j;
			else if(a[j]==i&&idx!=0) ne[idx]=j,idx=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(ne[j]!=0)
			{
				j=ne[j];
				cnt=0;
			}
			ans[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++) b[ans[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}