#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,X=15;
vector<int> v[N];
int pc[N];
bool vis[X],dg[X];
int dis[X];
void dfs(int x)
{
	//printf("dfs:%d\n",x);
	dg[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]] and !dg[v[x][i]])dfs(v[x][i]);
	}
}
int gs=0;
int dfs2(int a,int fa,int c)//0:正好未被影响，-x：已经被覆盖了，还能盖x-1个，x：未被覆盖，已经x次了
{
	int maxn=0,minn=0;
	for(int i=0;i<v[a].size();i++)
	{
		if(v[a][i]==fa)continue;
		int x=dfs2(v[a][i],a,c);
		if(x+1<0)minn=min(minn,x+1);
		else maxn=max(maxn,x+1);
	}
	int ans=(maxn>=minn?maxn:minn);
	if(ans==c)
	{
		gs++;
		ans=-c-1;
	}
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);//考试之后记得拿回水杯和纸巾
	freopen("hub.out","w",stdout);//考试之后记得拿回水杯和纸巾
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)v[i].resize(0);
		for(int i=1;i<n;i++)	
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if(c==7 or c==11 or c==12)
		{
			int l=0,r=n;
			while(l!=r)
			{
				int mid=(l+r)>>1;
				gs=0;
				dfs2(1,0,mid);
				if(gs<=k)
				{
					r=mid;
				}
				else l=mid+1;
			}
			printf("%d\n",l);
			continue;
		}
		if(13<=c and c<=14)
		{
			if(k==n)
			{
				printf("0\n");
				continue;
			}
			else if(k>=n/2)
			{
				printf("1\n");
				continue;
			}
			else if(k==1)
			{
				printf("%d\n",n/2+1);
			}
			for(int i=1;i<=n/2;i++)//这里只要有一个研究站，他的答案都不会超过n/2，因为答案是链答案+1，而链长为n/2，显然的，答案最大n/2
			{
				if(4*i+k>=n/2)
				{
					printf("%d\n",i+1);//计算的是链答案，因此加一
					break;
				}
			}
			continue;
		}
		for(int i=0;i<(1<<n);i++)
		{
			pc[i]=pc[i>>1]+(i&1);
		}
		int ztq=1e9;
		for(int i=0;i<(1<<n);i++)
		{
			if(pc[i]!=k)continue;
			for(int j=1;j<=n;j++)
			{
				vis[j]=i&(1<<(j-1));
			}
			int cnt=0;
			memset(dg,0,sizeof(dg));
			for(int i=1;i<=n;i++)
			{
				if(vis[i] and !dg[i])
				{
					cnt++;
					dfs(i);
				}
			}
			if(cnt>2)continue;
			memset(dis,0x3f,sizeof(dis));
			queue<int> q;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])
				{
					dis[i]=0;
					q.push(i);
				}
			}
			while(!q.empty())
			{
				int t=q.front();
				q.pop();
				for(int i=0;i<v[t].size();i++)
				{
					if(dis[v[t][i]]>dis[t]+1)
					{
						dis[v[t][i]]=dis[t]+1;
						q.push(v[t][i]);
					}
				}
			}
			int tqsj=0;
			for(int i=1;i<=n;i++)tqsj=max(tqsj,dis[i]);
//			if(tqsj<ztq)
//			{
//				printf("选择：\n");
//				for(int i=1;i<=n;i++)
//				{
//					if(vis[i])printf("%d ",i);
//				}
//				printf("\n答案为%d\n",tqsj);
//			}
			ztq=min(ztq,tqsj);
		}
		printf("%d\n",ztq);
	}
	return 0;
}//这里打不了太高档，我们打一个35分DP先试试。其次，那个特性特别好写，千万不要错过
//不对啊，这里DP有点麻烦，状态好像还是错的，那只能写个搜索了
/*
考虑k刚好为2，那么二分+贪心即可啊。若有点他的子树中最大深度刚好为那个值，加入。若有个点再次未覆盖了，在其上深度个加入。
这是真的吗？显然是吧，可惜没时间了
考虑记录子树中需要覆盖的状态为多少，然后直接贪！
*/