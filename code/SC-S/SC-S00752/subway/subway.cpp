#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
long long w[500005],x[500005][25],cnt[500005];
const int INF=1e9+5;
map<long long,long long> t[500005];
struct Edge{
	int to,next_,val;
}edge[5000005],edge2[500005];
int tot,head[505],head2[500005],tot2;
void add(int x,int y,int val)
{
	edge[++tot].to=y;
	edge[tot].next_=head[x];
	edge[tot].val=val;
	head[x]=tot;
	return ;
}
void add2(int x,int y)
{
	edge2[++tot2].to=y;
	edge2[tot2].next_=head2[x];
	head2[x]=tot2;
	return ;
}
long long dis[505];
bool flag[505];
struct Q{
	int d,id;
	bool operator < (const Q& x ) const{
		return d<x.d;
	}
};
priority_queue<Q> q;
void dij(int s)
{
	while(q.size()) q.pop();
	for(int i=1;i<=n;i++) dis[i]=INF,flag[i]=0;
	dis[s]=0;
	q.push({0,s});
	while(q.size())
	{
		Q x=q.top();
		q.pop();
		if(flag[x.id]==1) continue;
		flag[x.id]=1;
		for(int i=head[x.id];i;i=edge[i].next_)
		{
			int y=edge[i].to;
			//cout<<y<<" "<<edge[i].val<<"\n";
			if(dis[y]>dis[x.id]+edge[i].val)
				dis[y]=dis[x.id]+edge[i].val;
			q.push({dis[y],y});
		}
	}
	return ;
}
queue<int> qqq;
bool flag2[500005+500];
int lj[500005+500];
void bfs(int s,int t)
{
	for(int i=1;i<=n+m;i++) lj[i]=0,flag2[i]=0;
	while(qqq.size()) qqq.pop();
	qqq.push(s);
	while(qqq.size())
	{
		int x=qqq.front();
		qqq.pop();
		if(x==t) return ;
		for(int i=head2[x];i;i=edge2[i].next_)
		{
			int y=edge2[i].to;
			//cout<<y;
			if(flag2[y]==0)
			{
				qqq.push(y);
				lj[y]=x;
				flag2[x]=1;
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	long long T;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1,a;j<=k;j++)
		{
			scanf("%d",&a);
			scanf("%d",&t[i][a]);
			T=t[i][a];
			x[a][++cnt[a]]=i;
			//cout<<a<<" "<<m+i<<"\n";
			add2(a,i+m),add2(m+i,a);
		}
	}
	if(c>=12&&c<=19)
	{
		while(qq--)
		{
			int s,end;
			scanf("%d%d",&s,&end);
			bfs(s,end);
			int count=0,x=end;
			while(lj[x]!=0) 
			{
				if(x>m) count++;
				x=lj[x];
			}
			count--;
			printf("%lld\n",(long long)(w[s]+w[end]+count*T*2+2*T));
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i]-1;j++)
		{
			for(int o=j+1;o<=cnt[i];o++)
			{
				//cout<<x[i][j]<<" "<<x[i][o]<<" "<<t[x[i][j]][i]+t[x[i][o]][i]<<"\n";
				add(x[i][j],x[i][o],t[x[i][j]][i]+t[x[i][o]][i]);
				add(x[i][o],x[i][j],t[x[i][j]][i]+t[x[i][o]][i]);
			}
		}
	}
	while(qq--)
	{
		int s,end;
		scanf("%d%d",&s,&end);
		long long minn=INF;
		for(int i=1;i<=cnt[s];i++)
		{
			dij(x[s][i]);
			for(int j=1;j<=cnt[end];j++)
			{
				minn=min(minn,dis[x[end][j]]+w[s]+w[end]+t[x[s][i]][s]+t[x[end][j]][end]);
			}
		}
		printf("%lld\n",minn);
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
*/