#include<bits./stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> a[505];
vector<int> t[505];
vector<int> v[5005];
int solve(int x,int y)
{
	
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k;j++)
		{
			int A,T;
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<sovle(x,y)<<'\n';
	}
	return 0;
}

