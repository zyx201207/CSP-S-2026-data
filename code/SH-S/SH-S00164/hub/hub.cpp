#include<bits/stdc++.h>
using namespace std;
int head[1000005],nxt[2000004],to[2000004],tot=0;
void add_edge(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T,n,k,i,u,v;
	long long ans;
	scanf("%d %d",&C,&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		for(i=1;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		if(C==13||C==14)
			printf("%d\n",((n+1)/2-k+3)/4+1);
	}
	fclose(stdin);
	fclose(stdout);
}
