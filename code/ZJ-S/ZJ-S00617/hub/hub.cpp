#include<bits/stdc++.h>
#define int long long
#define sn 1000005
#define vivian 0x7fffffff
using namespace std;
int temptation=1,c,n,k,in[5],ans;
namespace graph{
	int to[sn],nxt[sn],hd[sn],dep[sn],fa[sn],cn=1,mj[sn],bis[sn],dis[sn];
	void ae(int x,int y)
	{
		cn++;
		to[cn]=y;
		nxt[cn]=hd[x];
		hd[x]=cn;		
	}
	queue<int> arc;
	bool chk()
	{
		while(arc.size())
		{
			arc.pop();
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(mj[i]&&!mj[fa[i]])
			{
				cnt++;
				arc.push(i);
			}
		}
		return cnt<=2;
	}
	void ddfs(int nw,int f,int d)
	{
		dep[nw]=dep[f]+1;
		d=mj[nw]?dep[nw]:d;
		bis[nw]=min(bis[nw],dep[nw]-d);
		for(int i=hd[nw];i;i=nxt[i])
		{
			int v=to[i];
			if(v!=f)
			{
				ddfs(v,nw,d);
			}
		}
	}
	int calcu()
	{
		for(int i=1;i<=n;i++)
		{
			bis[i]=vivian;
		}
		while(arc.size())
		{
			int nw=arc.front();
			arc.pop();
			ddfs(nw,0,1);
		}
		int sss=0;
		for(int i=1;i<=n;i++)
		{
			sss=max(sss,bis[i]);
		}
		return sss;
	}
	void adfs(int x,int sum)
	{
		if(x==n+1)
		{
			if(chk())
			{
				ans=min(ans,calcu());
			}
			return;
		}
		if(n-x+1+sum>k)
		{
			mj[x]=0;
			adfs(x+1,sum);
		}
		if(sum<k)
		{
			mj[x]=1;
			adfs(x+1,sum+1);
		}
	}
}
using namespace graph;
void dfs(int nw,int f)
{
	fa[nw]=f;
	for(int i=hd[nw];i;i=nxt[i])
	{
		int v=to[i];
		if(v!=f)
		{
			dfs(v,nw);
		}
	}
}
void berlichingen()
{
	cn=1,ans=vivian;
	for(int i=1;i<=n;i++)
	{
		hd[i]=0;
	}
}
void shinano()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>in[0]>>in[1];
		ae(in[0],in[1]);
		ae(in[1],in[0]);
	}
	dfs(1,0),adfs(1,0);
	cout<<ans<<'\n';
}
void anchorage()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		cin>>in[0]>>in[1];
		ae(in[0],in[1]);
		ae(in[1],in[0]);
	}
	int cnc=(n-1)/2;
	if(k==n)
	{
		cout<<0<<'\n';
		return;
	}
	if(cnc<=k)
	{
		cout<<1<<'\n';
		return;
	}
	cout<<(cnc-k+3)/4+1<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>temptation;
	while(temptation--)
	{
		berlichingen();
		if(c==14||c==13)
		{
			anchorage();
		}
		else
		{
			shinano();
		}
	}
	return 0;
}
