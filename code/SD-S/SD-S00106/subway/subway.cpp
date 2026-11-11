#include<bits/stdc++.h>
#define int long long
#define iint int
#define N 500010
using namespace std;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return x*f;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}

int c,n,m,ddd,qq;
int w[510];
struct edge
{
	int v,w;
	bool operator<(edge b)const
	{
		return w>b.w;
	}
};
vector<edge>e[N+100000];
unordered_set<int>hav[510];
unordered_map<int,int>t[510];//hav[µã]¡¾²ã¡¿ 
void add(int u,int v,int ww)
{
	e[u].push_back({v,ww});
//	e[v].push_back({u,ww});
}
int d[N],vis[N];
void dk(int st)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(0x3f));
	priority_queue<edge>q;
	for(auto cs:hav[st])
	{
		q.push({cs*n+st,w[st]+t[cs][st]});
		d[cs*n+st]=w[st];
	}
	while(!q.empty())
	{
		auto npt=q.top();
		q.pop();
		int u=npt.v;
		if(vis[u])continue;
//		cout<<u<<' '<<endl;
		vis[u]=1;
		for(auto to:e[u])
		{
			int v=to.v;
			if(d[v]>d[u]+to.w)
			{
				d[v]=d[u]+to.w;
//				cout<<v<<' '<<d[v]<<endl;
				q.push({v,d[v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),m=read(),n=read(),ddd=read(),qq=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=m;i++)
	{
		vector<int>ptt;
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int	pt=read();
			ptt.push_back(pt);
			t[i][pt]=read();
			for(auto cd:hav[pt])
			{
				int pt1=cd*n+pt,pt2=i*n+pt;
//				cout<<pt1<<' '<<pt2<<' '<<t[cd][pt]+t[i][pt]<<endl;
				add(pt1,pt2,t[cd][pt]+t[i][pt]);
				add(pt2,pt1,t[cd][pt]+t[i][pt]);
			}
			hav[pt].insert(i);
		}
		for(int k=1;k<ptt.size();k++)
		{
			add(ptt[k]+i*n,ptt[k-1]+i*n,0);
			add(ptt[k-1]+i*n,ptt[k]+i*n,0);
		}
//		for(int k=1;k<ptt.size();k++)
//		{
//			for(int j=0;j<k;j++)
//			{
////				cout<<k<<' '<<j<<endl;
//				add(ptt[j]+i*n,ptt[k]+i*n,t[i][ptt[k]]);
//				add(ptt[k]+i*n,ptt[j]+i*n,t[i][ptt[j]]);
////				cout<<ptt[j]+i*n<<' '<<ptt[k]+i*n<<' '<<t[i][ptt[j]]<<endl;
//			}
//		}
	}
	while(qq--)
	{
		int u=read(),v=read();
		dk(u);
		int ans=INT_MAX;
		for(auto cs:hav[v])
		{
			ans=min(ans,d[cs*n+v]+t[cs][v]);
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(auto cs:hav[i])
//			{
//				cout<<cs<<' '<<i<<' ';
//				for(auto pt:e[cs*n+i])
//				{
//					cout<<pt.v<<' ';
//					cout<<d[pt.v]<<endl;
//				}
//				cout<<endl;
//			}
//			cout<<endl;
//		}
		write(ans+w[v]);
		cout<<endl;
	}
	return 0;
}

