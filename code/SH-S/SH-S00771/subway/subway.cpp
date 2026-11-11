/*
	Name: µØÌúÕ¾ Subway Station 
	Copyright: Bulu(Geopelia is the best in the Pixel Tower!!)
	Author: Bulu feat.7999 
	Date: 2098.10.31
	Description: What do you want more than a Happy ending?
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<iomanip>
#include<cctype>
#include<climits>
#include<cmath>
#define int long long
using namespace std;
/**/
int c,n,m,d,q;
int w[510],t[510][510],a[510][510];
vector<pair<int,int>> g[100010];
int N=0;
int nline=512;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			g[i].push_back(make_pair(t[i][j],a[i][j]+nline));
			g[a[i][j]+nline].push_back(make_pair(t[i][j],i));
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		queue<int>
	}
}
