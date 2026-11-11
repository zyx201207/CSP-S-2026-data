#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int P=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;
int n,m,a[N],b[N],col[40][N],ans=0;
vector<int> g[40];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=30;i>=0;i--)
	{
		int y=(1<<i);
		for(int j=1;j<=n;j++)
		{
			if(b[j]>=y)
			{
				b[j]-=y;
				g[i].push_back(j);
			}
		}
	}
	for(int y=30;y>=0;y--)
	{
		if(g[y].size()>=m)
		{
			for(int i=0;i<g[y].size();i++)
			{
				int e=g[y][i];
				if(ans==0)ans=a[e];
				else ans=(ans&a[e]);
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}

