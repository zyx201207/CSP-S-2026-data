#include<bits/stdc++.h>

using namespace std;
struct pos
{
	int a[500005],k,t[500005];
};
pos b[501];
int w[100001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].k;
		for(int i=1;i<=b[i].k;i++)
		{
			cin>>b[i].a[i]>>b[i].t[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			
		}
	}
	return 0;
} 
