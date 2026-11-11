#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5,D=25;
int jinzhan[M],lline[N][M],t[N][M],bgin[Q],nd[Q],k[N];
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>jinzhan[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>lline[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)cin>>bgin[i]>>nd[i];
	for(int i=1;i<=q;i++)
	{
		cout<<jinzhan[bgin[i]]+jinzhan[nd[i]]+t[i][i]+t[i][i+1]<<endl;
	}
	return 0;
 } 
