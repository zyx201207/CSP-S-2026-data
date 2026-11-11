#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,q,w[1000005],k[1000005],vis[1000005],minn=INT_MAX;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	cin>>n>>m>>p>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		vis[k[i]]++;
	}
	for(int i=1;i<=q;i++)
	{
		minn=min(minn,vis[k[i]]);
	}
	cout<<minn<<endl;
	for(int i=1;i<=q;i++)
	{
		cout<<w[i]<<endl;
	}
	return 0;
}

