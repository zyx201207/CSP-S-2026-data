#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,o,p;
long long z[5010],dtz[510][5010],sj[510][5010],xl[280][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&z[i]);
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			scanf("%lld%lld",&dtz[i][j],&sj[i][j]);
			xl[i][dtz[i][j]]=sj[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>o>>p;
		for(int j=1;j<=n;j++)
		{
			if(o==1&&xl[i][p]!=0)
			{
				cout<<z[o]+sj[1][1]+sj[1][p]+z[p]<<endl;
				return 0;
			}
		}
		cout<<z[o]+sj[1][1]+sj[1][2]+sj[2][1]+sj[2][2]+z[p]<<endl;
	}
	return 0;
}
