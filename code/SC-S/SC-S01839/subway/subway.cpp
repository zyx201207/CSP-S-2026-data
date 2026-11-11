#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int mxnn=1e6+7;
const int mxx=INT_MAX;
int c,n,m,d,qwer[mxnn],k,s,e,ans,num,t,tmm,head[mxnn],tot,asdf=mxx;
bool jud[mxnn];
struct eg
{
	int u,v,w,nxt;
}edge[mxnn];
void add(int u,int v,int w)
{
	edge[tot++].u=u;
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].nxt=head[u];
	head[u]=tot;
}
void fd(int now,int goal,int res)
{
	for(int i=head[now];i;i=edge[i].nxt)
	{
		if(jud[edge[i].v])continue;
		res+=edge[i].w;
		if(edge[i].v==goal)asdf=min(asdf,res);
		jud[edge[i].v]=1;
		fd(edge[i].v,goal,res);
		jud[edge[i].v]=0;
		res-=edge[i].w;
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>tmm;
	for(int i=1;i<=m;i++)cin>>qwer[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>num>>t;
			add(m+i,num,t);
			add(num,m+i,t);
		}
	}
	for(int i=1;i<=tmm;i++)
	{
		cin>>s>>e;
		ans=qwer[s]+qwer[e];
		jud[s]=1;
		fd(s,e,0);
		ans+=asdf;
		cout<<ans<<endl;
	}
	return 0;
}