#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define mp(x,y) make_pair(x,y)
#define se second
#define fi first
using namespace std;
bool Beginning;

namespace Memory_Love{
	int read(){ int x=0; char ch=getchar(); bool flag=1;
		while(ch<'0' || ch>'9'){if(ch=='-') flag=0;ch=getchar();}
		while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return (flag==1? 1:-1)*x;}
	void write(int x,char ch=0){ if(x<0) x=-x,putchar('-');
		static short s[35],top=-1; do{s[++top]=x%10;x/=10;}while(x);
		while(~top) putchar(s[top--]+48); if(ch) putchar(ch);}
} using namespace Memory_Love;
const int N=5e5+505,M=505;
const int INF=0x3f3f3f3f3f3f3f3fll;
int Ntest,n,m,MaxSub,q,a[N];
//int Num,Pos[N],t[N];//Sub[N];
//map<PII,int> Map;

vector<PII> G[N];
void add(int u,int v,int w)
{
	G[u].push_back(mp(v,w));
}

int dist[M][M];
namespace Floyd
{
	void init()
	{
		memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=n;i++) dist[i][i]=0;
	}
	void build()
	{
		int i,j,k;
		for(i=1;i<=m;i++)
		{
			int len=G[i].size();
			for(j=0;j<len;j++)
			{
				for(k=0;k<len;k++)
				{
					if(j==k) continue;
					PII x=G[i][j],y=G[i][k];
					dist[x.fi][y.fi]=dist[y.fi][x.fi]=min(dist[x.fi][y.fi],x.se+y.se);
				}
			}
		}
	}
	void solve()
	{
		int i,j,k;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}


bool Ending;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,k,x,y,ans; Ntest=read(),n=read(),m=read(),MaxSub=read(),q=read();
	for(i=1;i<=m;i++) a[i]=read();
	for(k=1;k<=n;k++)
	{
		int cnt=read(); //Sub[k]=Sub[k-1]+cnt;
		for(i=1;i<=cnt;i++)
		{
			int x=read(),t=read();
			add(x,k,t);
		}
	}
	
	Floyd::init();
	Floyd::build();
	Floyd::solve();
	
	while(q--)
	{
		x=read(),y=read(),ans=INF;
		for(auto i:G[x])
		{
			for(auto j:G[y])
			ans=min(ans,i.se+j.se+dist[i.fi][j.fi]);
		}
		write(ans+a[x]+a[y],'\n');
	}
//	cerr<<"It used "<<(abs(&Beginning-&Ending)/1048576)<<" MB\n";
	return 0;
}
