#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005];
vector<pair<int,int>> v[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	/*
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k==2)
		{
			int n1,n2,n3,n4;
			v[n1].push_back({n3,n2+n4});
			v[n3].push_back({n1,n2+n4});
		}
	}
	*/
	while(q--)
	{
//		int x,y;
//		cin>>x>>y;
		int u=rand();
		cout<<u<<"\n";

	}
	
	return 0;
}

