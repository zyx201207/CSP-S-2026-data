#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
int w[500000],a[505][505],t[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=0;
		cout<<w[x]+w[y]+t[x][y]<<endl; 
	}
	return 0;
}
