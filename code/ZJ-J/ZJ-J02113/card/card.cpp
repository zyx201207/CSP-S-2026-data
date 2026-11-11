#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[300005],f,c[300005],cnt,b[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
		b[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(c[i]>1)
		{
			for(int j=i;j<=n;j++)
			{
				b[j]+=c[i]-1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
}
