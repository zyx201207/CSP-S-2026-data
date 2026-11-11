#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
int a[N],t[N];
vector<pair<int,int>> r[N];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		for(int j=1;j<=l;j++)
		{
			cin>>r[j].first>>r[j].second;
		}
	}
	while(q--)
	{
		int sx,ex;
		cin>>sx>>ex;
		int ans=w[sx]+w[ex];
		for(int i=sx;i<=ex;)
		{
			for(int j=1;j<=)
		}
	}
	return 0;
}
