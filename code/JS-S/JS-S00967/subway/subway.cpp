#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[505][500005];
long long w[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=n;i++)
	cin>>w[i];
	int k;
	for(long long i=1;i<=m;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int ai,ti;
			cin>>ai>>ti;
			a[ai][i]=ti;                                  
			}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++)
		if(a[x][i]!=0&&a[y][i]!=0)
		{
			cout<<w[x]+w[y]+a[x][i]+a[y][i]<<endl;
			break;
			}
		cout<<w[x]+w[y]+a[x][1]+a[y][1]<<endl;
	}
		return 0;
} 
