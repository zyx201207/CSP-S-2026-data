#include<bits/stdc++.h>
using namespace std;
int n,b[300005],ans[300005],a[500005],m,c[300005],d[300005];
int main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
		c[a[i]]++;
		ans[a[i]]=c[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[a[i]]!=i)
		{
			d[b[a[i]]+1]++;
			d[b[a[i]]+1]+=d[i];
		}
		else
		{
			d[i+1]++,d[i+1]+=d[i];
		}
		ans[a[i]]+=d[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}