#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],k[N];
vector<int> a[N],t[N];
int find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].size()==1) continue;
		if(a[i][0]==x)
		{
			return i;
		}
	}
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	while(q--)
	{
		int xr,yr;
		cin>>xr>>yr;
		int tmp=find(xr);
		while(tmp!=yr)
		{
//			tmp=find(a[tmp][1]);
		}
	}
	return 0;
}
