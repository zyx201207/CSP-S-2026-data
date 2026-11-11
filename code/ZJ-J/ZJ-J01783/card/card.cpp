#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],c[500005],ans[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(b[a[i]])
			c[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			while(c[j])
				j=c[j];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}

