#include<bits/stdc++.h>
#define u unsigned
#define ll long long
#define ull u ll
using namespace std;
struct edge{u v,w,nxt;}E[1000010];
struct node{u pos;ull v;};
u c,n,m,D,Q,T,cnt;
u w[500010],a,b,t,d[1000510];
ull minn[1000510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%u%u%u%u%u",&c,&n,&m,&D,&Q);
	for(u i=1;i<=m;i++){scanf("%u",&w[i]);}
	for(u i=1;i<=n;i++)
	{
		scanf("%u",&T);
		for(u j=1;j<=T;j++)
		{
			scanf("%u%u",&a,&t);
			E[++cnt]={a,t,d[m+i]};
			d[m+i]=cnt;
			E[++cnt]={m+i,t,d[a]};
			d[a]=cnt;
		}
	}
//	for(u i=1;i<=cnt;i++){cout<<"|||"<<E[i].v<<" "<<E[i].w<<" "<<E[i].nxt<<endl;}
	while(Q--)
	{
		scanf("%u%u",&a,&t);
		memset(minn,0x3f,sizeof(minn));
		queue<node> q;
		q.push({a,w[a]+w[t]});
		minn[a]=w[a]+w[t];
		while(!q.empty())
		{
			const node U=q.front();
			q.pop();
			if(U.v>minn[U.pos]){continue;}
//			for(u i=1;i<=n+m;i++){cout<<(minn[i]==4557430888798830399ull ? -1ll:(ll)minn[i])<<" ";}
//			cout<<endl<<">>>"<<U.pos<<" "<<U.v<<endl; 
			for(u i=d[U.pos];i;i=E[i].nxt)
			{
				if(minn[E[i].v]>E[i].w+U.v)
				{
					q.push({E[i].v,E[i].w+U.v});
					minn[E[i].v]=E[i].w+U.v;
				}
			}
		}
		printf("%llu\n",minn[t]);
	}
	return 0;
}
