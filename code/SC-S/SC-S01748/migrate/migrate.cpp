#include<bits/stdc++.h>
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
namespace fastio
{
	int read()
	{
		int z=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9')
		{
			if(c=='-')
			{
				f=-1;
			}
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			z=z*10+c-'0';
			c=getchar();
		}
		return z*f;
	}
	void write(int x)
	{
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		static int top=0,stk[106];
		while(x)
		{
			stk[++top]=x%10;
			x/=10;
		}
		if(!top)
		{
			stk[++top]=0;
		}
		while(top)
		{
			putchar(char(stk[top--]+'0'));
		}
	}
	void read(int *st,int *ed)
	{
		for(;st!=ed;st++)
		{
			(*st)=read();
		}
	}
	void write(int *st,int *ed)
	{
		for(;st!=ed;st++)
		{
			write(*st);
			putchar(' ');
		}
	}
}
using namespace fastio;
const int N=2e6+6;
int n,d,a[N],f[N],g[N],du[N];
vector<int>v[N];
namespace P1
{
	void solve()
	{
		int c=a[2]-a[1];
		int t=d/c;
		if(t<=1)
		{
			write(0);
			putchar('\n');
			return;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int ed=i+2*t-1;
			if(ed>n)
			{
				continue;
			}
			ans++;
		}
		write(ans);
		putchar('\n');
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		read(a+1,a+n+1);
		if(C==11||C==12)
		{
			P1::solve();
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				v[j].clear();
				du[j]=0;
				f[j]=1e18,g[j]=0;
			}
			for(int j=i;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[k]-a[j]<=d)
					{
						v[j].push_back(k);
						du[k]++;
					}
				}
			}
			queue<int>q;
			q.push(i);
			f[i]=0,g[i]=1;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(auto j:v[u])
				{
					if(f[j]>f[u]+1)
					{
						f[j]=f[u]+1;
						g[j]=g[u];
					}
					else if(f[j]==f[u]+1)
					{
						g[j]+=g[u];
					}
					du[j]--;
					if(!du[j])
					{
						q.push(j);
					}
				}
			}
			for(int j=i;j<=n;j++)
			{
				if(g[j]==2)
				{
					ans++;
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}