#include<bits/stdc++.h>
using namespace std;
int c, m, n, d, q, w[500050], a[550][550], t[550][550], x, y, k[500050];
int ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		for(int j=1;j<=n;j++)
		{
			if(a[j][x]!=0&&a[j][y]!=0)
			{
				ans+=a[j][x];
				ans+=a[j][y];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
