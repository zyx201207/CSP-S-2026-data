#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k[510],id;
long long w[500010];
vector<pair<int,long long> >a[510];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(inmt i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(inmt i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			id++;
			int x,z;
			cin>>x>>z;
			a[id+n].push_back({x,z});
			a[]
		}
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}