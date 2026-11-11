#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,e;
int w[1000010];
int a[210][8010];
int main()
{    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{   int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int j1;
			cin>>j1;
			a[i][j1]=1;
			cin>>t[i][j1];e=t[i][j];
		}
		a[i][0]=k;
	}
	while(q--)
	{
		int x,y;int xl,yl;
		cin>>x>>y;
		cout<<e*abs(y-x)endl;
	}
    return 0;
}

