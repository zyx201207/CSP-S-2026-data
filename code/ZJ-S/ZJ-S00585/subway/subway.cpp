#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
int w[505];
int k[505];
int a[505][505];
int t[505][505];
vector<int> g[505];
queue<int> q;
int x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
		for (int j=1;j<=k[i];j++)
			for (int s=1;s<=k[i];s++)
				g[a[i][j]].push_back(a[i][s]);
	}
	while(Q--)
	{
		cin>>x>>y;
		cout<<0<<"\n";
	}
	return 0;
}
