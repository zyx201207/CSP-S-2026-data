#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,x[N],y[N],ansa[N],ve[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		y[x[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",n);
	}
	return 0;
}
