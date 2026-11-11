#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;//0 ≤ c ≤ 25，1 ≤ n ≤ 500，1 ≤ m ≤∑n i=1 ki ≤ 5×105，1 ≤ d ≤ 20，1 ≤ q ≤ 105
int w[500010],b[510][500010],k[510];//b[i][t]t到i线站台
vector<int>a[500010];//i个地铁口有哪几条线 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x;
			cin>>x>>b[i][x];
			a[x].push_back(i); 
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		ll ans=LONG_MAX;
		cin>>x>>y;
		for(int j=0;j<=a[x].size();j++)//
			if(b[j][y])
				ans=min(ans,(b[j][x])*1ll+(b[j][y])*1ll);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
