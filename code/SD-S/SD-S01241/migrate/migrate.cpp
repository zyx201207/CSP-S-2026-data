#include<bits/stdc++.h>
#define int long long
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
const int N=2e6+5;
const int INF=0x3f3f3f3f3f3f3f3fll;
int n,m,a[N];
vector<int> G[50005];

namespace Sub1
{
	int deg[N],dist[N],cnt[N];
	void Topsort(int root)
	{
		int i; queue<int> q;
		for(i=root;i<=n;i++) deg[i]=0,cnt[i]=0,dist[i]=INF;
		for(i=root;i<=n;i++) for(auto j:G[i]) deg[j]++;
		q.push(root); cnt[root]=1,dist[root]=0;
		while(q.size())
		{
			int x=q.front();
			q.pop();
			for(auto y:G[x])
			{
				if(dist[y]==dist[x]+1) cnt[y]+=cnt[x];
				else if(dist[y]>dist[x]+1) dist[y]=dist[x]+1,cnt[y]=cnt[x];
				if(--deg[y]==0) q.push(y);
			}
		}
	}
	void Init()
	{
		for(int i=0;i<=n+3;i++)
		{
			G[i].clear();
		}
	}
	int Solve()
	{
		int i,j,Answer=0; Init(); n=read(),m=read();
		for(i=1;i<=n;i++) a[i]=read();
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=m) G[i].push_back(j);
				else break;
			}
		}
		for(i=1;i<=n;i++)
		{
			Topsort(i);
//			for(j=i+1;j<=n;j++) cerr<<i<<' '<<j<<' '<<dist[j]<<' '<<cnt[j]<<'\n';
			for(j=i+1;j<=n;j++) if(cnt[j]==2) Answer++;
		}
		return Answer;
	} 
}

struct Bree
{
	int tree[N];
	int lowbit(int x)
	{
		return (x&-x);
	}
	void init(int n)
	{
		for(int i=1;i<=n;i++) tree[i]=0;
	}
	void ADD(int i,int x)
	{
		for(;i<=n;i+=lowbit(i))
			tree[i]+=x;
	}
	int query(int i)
	{
		int sum=0;
		for(;i;i-=lowbit(i))
			sum+=tree[i];
		return sum;
	}
}BIT;

namespace SubB
{
	int P[N],Far[N];
	int Solve()
	{
		int i,Pos=0,cnt=0,Answer=0; n=read(),m=read();
		for(i=1;i<=n;i++) a[i]=read();
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[1]<=m && a[n]-a[i]<=m)
			{
				Pos=i; break;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i==Pos) continue;
			a[++cnt]=a[i];
		}
//		for(i=1;i<=n;i++) cerr<<a[i]<<' ';
		n=cnt; BIT.init(n);
		for(i=n,Pos=n;i>=1;i--)
		{
			while(Pos>i || (Pos>1 && a[i]-a[Pos-1]<=m)) Pos--;
			P[i]=Pos;
		}
		for(i=1,Pos=1;i<=n;i++)
		{
			while(Pos<i || (Pos<n && a[Pos+1]-a[i]<=m)) Pos++;
			Far[i]=Pos;
		}
		for(i=n,Pos=n;i>=1;i--)
		{
			while(Pos>=Far[i])
			{
				BIT.ADD(P[Pos],1);
				BIT.ADD(P[Pos]+1,-1);
				Pos--;
			}
			Answer+=BIT.query(Far[i]);
		}
		return Answer;
	}
}

bool Ending;
signed main()
{
//	freopen("sample.in","r",stdin);
//	freopen("sample.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--)
	{
		if(c==13 || c==14) write(SubB::Solve(),'\n');
		else write(Sub1::Solve(),'\n');
	}
//	cerr<<"It used "<<(abs(&Beginning-&Ending)/1048576)<<" MB\n";
	return 0;
}
