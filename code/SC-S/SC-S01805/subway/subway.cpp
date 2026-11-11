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














int c,n,m,d,q;
constexpr int MAXM=5e5+10;
constexpr int MAXN=520;
constexpr int MAXD=25;
int w[MAXM];
int k[MAXN];
vector <int> a[MAXN],t[MAXN];
vector <int> gx[MAXM],id[MAXM];
constexpr int MAXQ=1e5+10;
int ql[MAXQ],qr[MAXQ];
void init()
{
	c=read<int>(); n=read<int>(); m=read<int>(); d=read<int>(); q=read<int>();
	for(int i=1;i<=m;i++) w[i]=read<int>();
	for(int i=1;i<=n;i++)
	{
		k[i]=read<int>();
		for(int j=1,ca,ct;j<=k[i];j++)
		{
			ca=read<int>();
			ct=read<int>();
			a[i].emplace_back(ca);
			t[i].emplace_back(ct);
			gx[ca].emplace_back(i);
			id[ca].emplace_back(j-1);
		}
	}
	for(int i=1;i<=q;i++)
	{
		ql[i]=read<int>();
		qr[i]=read<int>();
	}
	return;
}
typedef long long ll;
ll dis[MAXN][MAXN];
typedef pair<int,ll> pii;
vector <pii> g[MAXN];
constexpr ll INF=1e18;
void build()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int siz=gx[i].size();
		if(siz>1)
		{
			for(int jl=0;jl<siz;jl++)
			{
				for(int jr=jl+1;jr<siz;jr++)
				{
					int li=gx[i][jl],ri=gx[i][jr];
					int idxl=id[i][jl],idxr=id[i][jr];
					//dis[li][ri]=dis[ri][li]=min(dis[li][ri],(ll)t[li][idxl]+t[ri][idxr]);
					g[li].push_back(make_pair(ri,(ll)t[li][idxl]+t[ri][idxr]));
					g[ri].push_back(make_pair(li,(ll)t[li][idxl]+t[ri][idxr]));
				}
			}
		}
	}
	priority_queue <pii> q;
	for(int i=1;i<=n;i++)
	{
		q.push(make_pair(0,i));
		while(!q.empty())
		{
			int u=q.top().second;
			int dd=q.top().first;
			q.pop();
			if(dd>dis[i][u]) continue;
			int siz=g[u].size();
			for(int j=0;j<siz;j++)
			{
				int v=g[u][j].first;
				ll ww=g[u][j].second;
				if(dis[i][v]>dis[i][u]+ww)
				{
					dis[i][v]=dis[i][u]+ww;
					q.push(make_pair(dis[i][v],v));
				}
			}
		}
	}
	return;
}
void query()
{
	for(int i=1;i<=q;i++)
	{
		int l1=gx[ql[i]].size(),l2=gx[qr[i]].size();
		ll ans=INF;
		for(int k1=0;k1<l1;k1++)
		{
			for(int k2=0;k2<l2;k2++)
			{
				ans=min(ans,dis[gx[ql[i]][k1]][gx[qr[i]][k2]]+t[gx[ql[i]][k1]][id[ql[i]][k1]]+t[gx[qr[i]][k2]][id[qr[i]][k2]]);
			}
		}ans+=w[ql[i]]+w[qr[i]];
		write<ll>(ans,'\n');
	}
	return;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	init();
	build();
	query();
	
	flush(); 
	fclose(stdin); fclose(stdout);
	return 0;
}