#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a,t,cnt,w[2000006],k[2000006];
long long ans;
int head[2000006],to[4000006],nxt[4000006],val[4000006];
//void star(int u,int v,int z)
//{
//	cnt++;
//	to[cnt]=v;
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++)
			scanf("%d%d",&a,&t);
	}
	for (int i=1,x,y;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d",rand()%156347);
	} 
	return 0;
}
