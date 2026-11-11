#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],aa[500005],t[500005];
int a[5005][5005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(a,0x3f,sizeof(a));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int i,j,l;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>aa[j]>>t[j];
		}
		for(j=1;j<=k;j++)
		{
			for(l=j+1;l<=k;l++)
			{
				a[aa[j]][aa[l]]=min(a[aa[j]][aa[l]],t[j]+t[l]);
				a[aa[l]][aa[j]]=min(a[aa[l]][aa[j]],t[j]+t[l]);
			}
		}
	}
	/*for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==0x3f3f3f3f3f3f3f3f)
			{
				cout<<"* ";
			}
			else cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(l=1;l<=m;l++)
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=min(a[i][j],a[i][l]+a[l][j]);
			}
		}
	}
	while(q--)
	{
		int x,r;
		cin>>x>>r;
		cout<<w[x]+a[x][r]+w[r]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/