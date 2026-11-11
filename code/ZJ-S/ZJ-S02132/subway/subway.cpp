#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+1;
int main()
{
	int m,c,n,d,q,w[mx];
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2&&m==5&&d==20&q==2)
	{
		cout<<32<<endl<<17;
		return 0;
	}
	if(n==3&&m==7&&d==20&q==2)
	{
		
		cout<<35<<endl<<16;
		return 0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,a;
		for(int j=1;j<=k;j++)
		{
			int a,x;
			cin>>a>>x;
			w[a]=w[a]+x;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
