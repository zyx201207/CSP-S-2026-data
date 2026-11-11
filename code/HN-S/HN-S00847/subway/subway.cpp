#include<bits/stdc++.h>
using namespace std;
#define N 1005
int w[N]={0};
int k[N]={0};
int a[N][N]={0},t[N][N]={0};
int px[N]={0},py[N]={0};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int time;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++)
	{
		cin>>px[r]>>py[r];
	}
	for(int r=1;r<=q;r++)
	{
		time=w[px[r]]+t[1][px[r]]+t[1][py[r]]+w[py[r]];
		cout<<time<<endl;
	}	
}
