#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],a[600][600],t[600][600],p[600];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int sum=0;
	int flag=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k>2)
		{
			flag=0;
		}
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		sum+=w[x]+w[y];
		for(int i=1;i<=n/2;i++)
		{
			sum+=w[i];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
