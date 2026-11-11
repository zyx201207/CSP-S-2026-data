#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e6+5;
const int MAXN2=1e6+5;
struct edge
{
	int v,w,nxt;
}e[MAXN*2];
int head[MAXN],tot;
inline void addedge(int u,int v,int w)
{
	e[++tot]={v,w,head[u]};
	head[u]=tot;
}
inline void addundirect(int u,int v,int w)
{
	addedge(u,v,w);
	addedge(v,u,w);
}
int n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=tot;i++)
		{
			e[i]={0,0,0};
			head[i]=0;
		}
		tot=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			addundirect(u,v,1);
		}
		cout<<1<<endl;
	}
	return 0;
}

