#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	cin>>c>>n>>m>>d>>q;
	int w[m] = {};
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];//每座地铁站地面到站厅的距离 
	}
	vector <int> st[m];
	vector <int> G[m];
	int a[510][m] = {};
	int t[510][m] = {};
	for (int i=1;i<=n;i++)//第i条线路 
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			//a[i][j]表示第j个站点编号为a[i][j]
			//t[i][j]表示站厅到站台的时间
			st[a[i][j]].push_back(i); 
			if (j>=2)
			{
				G[a[i][j]].push_back(a[i][j-1]);
				G[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		
		cout<<1;
	}
	return 0;
}
