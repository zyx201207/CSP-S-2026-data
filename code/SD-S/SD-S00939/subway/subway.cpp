#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1005],t[505][505],k,x[505],y[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		cin>>t[i][k];
	}
	for(int i=1;i<=q;i++) 
	{
		cin>>x[i]>>y[i];
	}
	
	return 0;
 } 
