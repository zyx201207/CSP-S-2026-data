#include <bits/stdc++.h>
namespace FastIO
{
	constexpr int BUF=1<<22;
	char inbuf[BUF],outbuf[BUF];
	char *p1=inbuf,*p2=outbuf;
	int outpos=0;
	char gc()
	{
		if(p1==p2)
		{
			p2=(p1=inbuf)+fread(inbuf,1,BUF,stdin);
			if(p1==p2) return EOF;
		}
		return *p1++;
	}
	template<class T>
	T read()
	{
		T x=0;
		bool f=false;
		char ch=gc();
		while(ch>'9'||ch<'0')
		{
			if(ch=='-') f=true;
			ch=gc();
		}
		while(ch>='0'&&ch<='9')
		{
			x=(x<<3)+(x<<1)+(ch^48);
			ch=gc();
		}
		return f?-x:x;
	}
	void flush()
	{
		fwrite(outbuf,1,outpos,stdout);
		outpos=0;
		return ;
	}
	template <class T>
	void write(T x,char endch=' ')
	{
		if(outpos>BUF-32) flush();
		if(x<0) outbuf[outpos++]='-',x=-x;
		if(x==0) outbuf[outpos++]='0';
		else
		{
			char tmp[64]={};
			int top=0;
			while(x)
			{
				tmp[top++]=(x%10)+48;
				x/=10;
			}
			while(top)
			{
				outbuf[outpos++]=tmp[--top];
			}
		}
		outbuf[outpos++]=endch;
		return;
	}
}


using namespace std;
using FastIO::read;
using FastIO::write;
using FastIO::flush;
 













int c,t;
int n,k;
constexpr int MAXN=2e6+10;
bool v[MAXN];
int tmp[MAXN];
int vis[MAXN];
vector <int> g[MAXN];

void dfs(int u)
{
	vis[u]=t;
	int len=g[u].size();
	for(int i=0;i<len;i++)
	{
		int vv=g[u][i];
		if(v[vv]&&vis[vv]<t) dfs(vv);
	}
	return;
}

int find(int rt)
{
	queue < pair<int,int> > q;
	bool fff[MAXN]={};
	q.push(make_pair(0,rt));
	fff[rt]=1;
	while(!q.empty())
	{
		int u=q.front().second;
		int step=q.front().first;
		q.pop();
		if(v[u])
		{
			return step;
		}
		int len=g[u].size();
		for(int i=0;i<len;i++)
		{
			if(fff[g[u][i]]==0)
			{
				fff[g[u][i]]=1;
				q.push(make_pair(step+1,g[u][i]));
			}
		}
	}
	return 10086;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	c=read<int>(); t=read<int>();
	while(t--)
	{
		n=read<int>(); k=read<int>();
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			v[i]=0;
			tmp[i]=0;
			g[i].clear();
		}
		for(int i=1,u,v;i<n;i++)
		{
			u=read<int>(); v=read<int>();
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		int tt=(1<<n)-1;
		for(int b=0;b<=tt;b++)
		{
			for(int i=1;i<=n;i++) vis[i]=0;
			int cur=1,cnt=0;
			int bb=b;
			while(bb)
			{
				if(bb&1) v[cur]=1,tmp[++cnt]=cur;
				else v[cur]=0;
				bb=bb>>1;
			}
			if(cnt!=k) continue;
			int cnt2=0;
			for(int i=1;i<=cnt;i++)
			{
				if(vis[tmp[i]]<t)
				{
					dfs(tmp[i]);
					cnt2++;
				}
			}
			if(cnt2>2) continue;
			int curans=1;
			for(int i=1;i<=n;i++)
			{
				if(v[i]) continue;
				curans=max(curans,find(i));
			}
			ans=min(curans,ans);
		}
		write<int>(ans,'\n');
	}
	
	flush(); 
	fclose(stdin); fclose(stdout);
	return 0;
}