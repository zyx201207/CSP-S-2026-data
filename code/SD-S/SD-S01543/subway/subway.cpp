#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=5e5+10;
int c,n,m,d,q;
int w[N];
int k[510];
vector<int>a[510],t[510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		a[i].push_back(-1);
		t[i].push_back(-1);
		for(int j=1;j<=k[i];++j)
		{
			int ai,ti;
			cin>>ai>>ti;
			a[i].push_back(ai);
			t[i].push_back(ti);
		}
	}

	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][1]+t[1][1]<<"\n";
	}
	return 0;
}
/*
Oct31==Dec25?
*/
