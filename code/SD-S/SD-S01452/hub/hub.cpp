#include<bits/stdc++.h>
#define itn int
using namespace std;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int c,t;
itn n,k;
const int N=1000010;
vector<int> ed[N];
//int st[N][25];
int dep[N],f[N];
int len[N];
int maxs[N];
void dfs(int now,int fa)
{
	//st[now][0]=fa;
	//for(int i=1;i<=20;i++) st[now][i]=st[st[now][i-1]][i-1];
	dep[now]=dep[fa]+1;
	f[now]=fa;
	for(int i:ed[now]) if(i!=fa) 
	{
		dfs(i,now);
		len[now]=max(len[now],len[i]);
	}
	len[now]++;
}
//priority_queue<pair<int,int> > q;
bool ot[N],yot[N];
int ct;
int ylen[N];
int llen[N];
queue<int> q;
bool check(int mid)
{
	int ycnt=0;
	memset(yot,0,sizeof(yot));
	memset(ylen,0,sizeof(ylen));
	for(int i=1;i<=n;i++) if(len[i]>mid) yot[i]=1,ycnt++;
	itn cnt;
	for(int i=1;i<=n;i++) if(yot[i]) for(int j:ed[i]) if(!yot[j]) ylen[i]=max(ylen[i],len[j]);
	//dfs2(ct);
	int lt=0;
	for(int i=1;i<=n;i++) if(yot[i])
	{
	lt=i;
	while(!q.empty()) q.pop();
	q.push(lt);
	cnt=ycnt;
	for(int j=1;j<=n;j++) llen[j]=ylen[j],ot[j]=yot[j];
	//if(llen[i]+1>mid) continue;
	while(!q.empty())
	{
		int num=q.front();
		q.pop();
		if(llen[num]+1>mid) continue;
		for(itn j:ed[num]) if(ot[j]) 
		{
			llen[j]=max(llen[j],llen[num]+1);
			q.push(j);
		}
		ot[num]=0;
		cnt--;
	}if(cnt<=k) return 1;
	}
	//if(ycnt==k) return 1;
	//cout<<mid<<' '<<ycnt<<'\n';
	
	return 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;i++) ed[i].clear();
		memset(dep,0,sizeof(dep));
		for(itn i=1;i<n;i++)
		{
			int u,v;
			u=read();v=read();
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		dfs(1,0);
		int maxn=0,maxi;
		for(int i=1;i<=n;i++) if(maxn<dep[i])
		{
			maxn=dep[i];
			maxi=i;
		}
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa)); 
		dfs(maxi,0);
		maxn=0;
		int maxj;
		for(int i=1;i<=n;i++) if(maxn<dep[i])
		{
			maxn=dep[i];
			maxj=i;
		}
		for(int i=1;i<=maxn/2;i++) maxj=f[maxj];
		ct=maxj;
		//cout<<ct<<'\n';
		memset(dep,0,sizeof(dep));
		memset(len,0,sizeof(len));
		dfs(ct,0);
		//cout<<'\n';
		int l=0,r=maxn;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		//for(int i:ed[now]) q.emplace(len[i],i);
		cout<<l<<'\n';
		//cout<<'\n';
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

