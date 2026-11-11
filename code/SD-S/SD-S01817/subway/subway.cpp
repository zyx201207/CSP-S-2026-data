#include<bits/stdc++.h>
using namespace std;
int w[500005],k[1000],a[600][20005],t[600][20005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	while(q>0)
	{
		q--;
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+2*t[1][1]+2*t[1][1]*abs(x-y)<<endl;
	}
	return 0;	
} 
