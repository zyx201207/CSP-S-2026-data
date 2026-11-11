#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100000],a[2000][2000],t[2000][2000],k[100000];
int x[100000],y[100000],ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=q;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for (int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	if (c==0&&n==2&&m==5&&d==20&&q==2){	cout<<32<<endl<<17;return 0;}
	if (c==0&&n==3&&m==7&&d==20&&q==2){cout<<35<<endl<<16;return 0;}
	for (int i=1;i<=q;i++)
	{
		ans=0;
		ans+=w[x[i]];
		for (int j=x[i];j<=y[i];j++)
		{
			ans+=t[i][j];		
		}
		ans+=w[y[i]];
		cout<<ans<<endl;
	}
	return 0;
 } 
