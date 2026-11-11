#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &s){
	int f=1;
	char ch=getchar();
	s=0;
	while(!isdigit(ch)){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	s*=f;
}
int n,k,ans;
int tot,head[300005],to[600005],nxt[600005];
int son[300005],f[300005][2];
inline void add_edge(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs1(int u,int pre)
{
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre)
			continue;
		dfs1(v,u);
		if(f[v][0]+1>f[u][0])
		{
			son[u]=v;
			f[u][1]=f[u][0];
			f[u][0]=f[v][0]+1;
		}
		else if(f[v][0]+1>f[u][1])
			f[u][1]=f[v][0]+1;
	}
}
void dfs2(int u,int pre)
{
	if(f[pre][u==son[pre]]+1>f[u][0]){
		son[u]=pre;
		f[u][1]=f[u][0];
		f[u][0]=f[pre][u==son[pre]]+1;
	}
	else if(f[pre][u==son[pre]]+1>f[u][1])
		f[u][1]=f[pre][u==son[pre]]+1;
	ans=max(ans,f[u][0]+f[u][1]);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre)
			continue;
		dfs2(v,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	read(c); read(T);
	if(c==11||c==12)
	{
		while(T--)
		{
			memset(head,0,sizeof(head));
			memset(son,0,sizeof(son));
			memset(f,0,sizeof(f));
			tot=0; ans=0;			
			read(n); read(k);
			for(int u,v,i=1;i<n;++i)
			{
				read(u); read(v);
				add_edge(u,v);
				add_edge(v,u);
			}
			dfs1(1,0);
			dfs2(1,0);
			if(k==1)
				printf("%d\n",(ans+1)/2);
			else
				printf("%d\n",(int)ceil(ans*1.0/4));
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

