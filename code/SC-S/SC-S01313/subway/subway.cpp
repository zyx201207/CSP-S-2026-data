#include<bits/stdc++.h>
using namespace std;
const int N=500,M=20;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

int g[N+10][N+10];
void add(int a,int b,int z){
	if(g[a][b]==0) g[a][b]=z;
	else if(z<g[a][b]){
		g[a][b]=z;
	}
}

int c,n,m,d,q; 
int w[M+10];
int a[N+10][M+10],t[N+10][M+10];

int dis[N+10];
bool vis[N+10];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;

void dijkstra(int start)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	que.push({0,start});
	vis[start]=1; dis[start]=0;
	
	while(!que.empty())
	{
		int now=que.top().second; 
		int now_d=que.top().first;
		que.pop(); vis[now]=1;
		
		for(int i=1; i<=m; i++)
		{
			if(g[now][i] && !vis[i])
			{
				if(now_d+g[now][i]<dis[i]){
					dis[i]=now_d+g[now][i];
					que.push({dis[i],i});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1; i<=m; i++) w[i]=read();
	for(int i=1; i<=n; i++)
	{
		int k=read();
		for(int j=1; j<=k; j++){
			a[i][j]=read(); t[i][j]=read();
		}
		
		for(int a1=1; a1<=k; a1++){
			for(int a2=1; a2<=k; a2++){
				if(a1!=a2){
					add(a[i][a1],a[i][a2],t[i][a1]+t[i][a2]);
					add(a[i][a2],a[i][a1],t[i][a1]+t[i][a2]);
				} 
			}
		}
	}
	/*for(int i=1; i<=m; i++){
		for(int j=1; j<=m; j++){
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}*/
	while(q--)
	{
		int qd=read(),zd=read();
		dijkstra(qd);
		printf("%d\n",dis[zd]+w[qd]+w[zd]);
	}
	return 0;
}
