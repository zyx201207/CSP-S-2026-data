#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,u=1;
int w[500050],k[500050],x[500050],y[500050],e[500050];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k[1];
		for(j=2;j<=k[1]*2+1;j++)
		{
			cin>>k[j];
			t=t+k[j];
		}
		e[u]=t+k[1];
		t=0;
		u++;
	}
	for(i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(i=1;i<=q;i++)
	{
		e[i+n]=e[i];
	}
	for(i=1;i<=q;i++)
	{
		cout<<x[i]+y[i]+e[i]<<endl;
	}
	return 0;
}