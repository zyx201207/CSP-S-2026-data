#include <iostream>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m],a[n][m][2];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>a[i][j][1]>>a[i][j][2];
		}
		
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;

	}
	return 0;
 } 
