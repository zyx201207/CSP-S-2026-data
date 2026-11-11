#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10;
int c,n,m,d,q,k[510],a[510][M],w[M];
vector<int> dis[M]; 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			int aa,tt;
			cin>>aa>>tt;
			a[i][aa]=tt;
		}
	}
	return 0;
}
