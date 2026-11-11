#include <bits/stdc++.h> 
using namespace std;
int c,m,n,p,q,w[500005],k,s,t,a[505][500005],minn=1000005,x,y;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>s>>t;
			a[i][s]=t;
		}
	}
	while(q--)
	{
		
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
