#include<bits/stdc++.h>
#define int long long
using namespace std;
const int cxk=1000;
int r[cxk][cxk],n,m,c,d,q,k[cxk],a[cxk][cxk],t[cxk][cxk],w[cxk];
vector<int>v[cxk];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		for(int j=1;j<=m;j++)
			r[i][j]=1e16; 
		r[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(t[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:v[i])
		{
			for(int j=1;j<=m;j++)
			{
				for(auto y:v[j])
					r[i][j]=min(r[i][j],x+y);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		if(to[x[i]]==0)to[x[i]]=++m;
		if(to[y[i]]==0)to[y[i]]=++m;
		r[to[x[i]]][x[i]]=
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				r[i][j]=min(r[i][j],r[i][k]+r[k][j]);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
