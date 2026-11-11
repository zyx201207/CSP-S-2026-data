#include<bits/stdc++.h>
using namespace std;

const int N = 510;
const int M = 5e5+10;
int c,n,m,d,q,x,y;
int k[N];
int w[M];
int a[N][M];
int t[N][M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k[i];
		for(int j = 1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	while(q--)
	{
		cin>>x>>y;
		
	}
	return 0;
}
