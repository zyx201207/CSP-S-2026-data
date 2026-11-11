#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll i,j,c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i]*2;j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--)
	{
		cin>>x>>y;
		
	}
	return 0;
}
