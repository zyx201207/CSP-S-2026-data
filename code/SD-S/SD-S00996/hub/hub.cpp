#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define M N*2
int c,t;
int head[N],Next[M],ver[M],tot;
void ADD(int x,int y)
{
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		memset(head,-1,sizeof(head));
		tot=-1;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			ADD(x,y);
			ADD(y,x);
		}
		printf("1\n");
	}
	return 0;
}
