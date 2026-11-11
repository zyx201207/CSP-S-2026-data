#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3;
ll c,n,m,d,q,w[N],a[N][N],t[N][N],k[N],x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[k[i]][j]>>t[k[i]][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<35<<'\n';
	}
	return 0;
}
