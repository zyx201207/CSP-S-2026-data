#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a,t[500005],x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a;
			cin>>t[a];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<w[x]+t[x]+t[y]+w[y]<<'\n';
	}
	return 0;
 } 
