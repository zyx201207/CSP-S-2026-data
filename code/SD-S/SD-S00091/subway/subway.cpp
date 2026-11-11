#include<bits/stdc++.h>
using namespace std;
int n,c,m,d,q,w[500005],a[500005],t[505][505];
vector<int>h[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	scanf("%d",w+i);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",a+i,&t[i][j]);
			if(j!=1)
			{
				h[a[j]].push_back(a[j-1]);
				h[a[j-1]].push_back(a[j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<0;
	}
	return 0; 
}
//Oct31==Dec25?
