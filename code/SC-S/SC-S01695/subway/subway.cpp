#include <bits/stdc++.h>
using namespace std;
int m,w[500010],n,c,d,q,k,x,y;
struct Xian
{
	int k,a[50010],t[50010];
};
Xian xi[510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>xi[i].k;
		for(int j=1;j<=k;j++)
		{
			cin>>xi[i].a[j]>>xi[i].t[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
	}
	return 0;
}