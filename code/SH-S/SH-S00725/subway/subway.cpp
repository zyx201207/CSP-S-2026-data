#include<bits/stdc++.h>
using namespace std;

int read()
{
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c))
	{
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret;
}
const int M=1010;
int n,m,d,q;
int w[M];
int a[M];
int t[M];
struct node{
	int v,w;
	friend bool operator <(const node s1,const node s2)
	{
		if(s1.w==s2.w) return s1.v>s2.v;
		return s1.w>s2.w;
	}
};
vector <node> mp[M];
int dis[M][M];
priority_queue <node> pq;
bool vis[M];
void djs(int num)
{
	while(!pq.empty()) pq.pop();
	node cur,nxt;
	memset(dis[num],0x3f,sizeof(dis[num]));
	memset(vis,0,sizeof(vis));
	nxt.v=num;
	nxt.w=0;
	pq.push(nxt);
	dis[num][num]=0;
	while(!pq.empty())
	{
		cur=pq.top();
		pq.pop();
		if(vis[cur.v]) continue;
		vis[cur.v]=1;
		
		for(int i=0;i<mp[cur.v].size();i++)
		{
			nxt=mp[cur.v][i];
			if(vis[nxt.v]) continue;
			if(dis[num][nxt.v]>dis[num][cur.v]+nxt.w)
			{
				dis[num][nxt.v]=dis[num][cur.v]+nxt.w;
				nxt.w=dis[num][nxt.v];
				pq.push(nxt);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);//Oct31==Dec25?
	freopen("subway.out","w",stdout);
	int c=read();
	n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	node inn;
	for(int i=1;i<=n;i++)
	{
		int K=read();
		for(int j=1;j<=K;j++)
		{
			a[j]=read();
			t[j]=read();
			for(int k=1;k<j;k++)
			{
				inn.v=a[j];inn.w=t[j]+t[k];
				mp[a[k]].push_back(inn);
				inn.v=a[k];
				mp[a[j]].push_back(inn);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		x=read();y=read();
		if(dis[x][y]==0&&dis[y][x]==0) djs(x);
		int ans=dis[x][y]+w[x]+w[y];
		printf("%d",ans);
		if(i<q) printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
