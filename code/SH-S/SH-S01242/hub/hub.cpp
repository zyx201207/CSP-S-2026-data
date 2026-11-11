#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
}
using IO::rd;
#define pii pair<int,int>
#define a first
#define b second
int hd[1000100],to[2000200],ne[2000200],tot=2;
int pa[1000100],ht[1000100],deg[1000100],_deg[1000100];
bool vis[1000100];
void add(int x,int y)
{
	to[tot]=y;ne[tot]=hd[x];
	hd[x]=tot++;
	_deg[x]++;
}
int q[1000100];
int n,k;
int b[1000100],c;
int rtt[1000100],cr;
int fl[1000100],fr[1000100];
int slv2(int d,int x)
{
	// cerr<<"SLV2: "<<d<<' '<<x<<endl;
	c=0;
	b[c++]=d;x=pa[x];
	while(x&&deg[x]==2)b[c++]=ht[x],x=pa[x];
	if(x==0)
	{
		assert(cr!=-1);
		if(!cr)
		{
			cr=c;for(int i=0;i<c;i++)rtt[i]=b[i];
			return 0;
		}
		for(int i=cr-2;i>=0;i--)b[c++]=rtt[i];
		cr=-1;c--;
	}
	else b[c]=d;
	for(int i=0;i<=c;i++)fl[i]=fr[i]=0;
	for(int i=1;i<=c;i++)fl[i]=min(fl[i-1]+1,d-b[i]);
	for(int i=c-1;i>=0;i--)fr[i]=min(fr[i+1]+1,d-b[i]);
	int ans=0;
	for(int i=1;i<c;i++)ans=max(ans,min(fl[i],fr[i])*2-1);
	for(int i=1;i<c;i++)ans=max(ans,min(fl[i],fr[i+1])*2);
	return ans;
}
bool chk(int d)
{
	// cerr<<"CHK: "<<d<<' '<<n<<endl;
	for(int i=1;i<=n;i++)vis[i]=0,ht[i]=0,deg[i]=_deg[i];
	// cerr<<"DEG: ";for(int i=1;i<=n;i++)cerr<<deg[i]<<' ';cerr<<endl;
	int l=0,r=0;
	for(int i=1;i<=n;i++)if(deg[i]==1)q[r++]=i;
	for(int i=0;i<d;i++)
	{
		if(r==n)return 1;
		int tr=r;
		while(l<tr)
		{
			int x=q[l++];vis[x]=1;
			int y=pa[x];
			if(1==--deg[y])q[r++]=y;
			ht[y]=max(ht[y],i+1);
		}
	}
	// cerr<<"VIS: ";for(int i=1;i<=n;i++)cerr<<vis[i]<<' ';cerr<<endl;
	cr=0;int ans=0;
	for(int i=1;i<=n;i++)if(!vis[i]&&pa[i]&&deg[i]!=2)ans=max(ans,slv2(d,i));
	return n-l-ans<=k;
}
int slv()
{
	n=rd();k=rd();tot=2;
	for(int i=1;i<=n;i++)hd[i]=0,_deg[i]=0,vis[i]=0;
	for(int i=1;i<n;i++)
	{
		int q=rd(),w=rd();
		add(q,w);add(w,q);
	}
	for(int i=1;i<=n;i++)deg[i]=_deg[i];
	// cerr<<"DEG: ";for(int i=1;i<=n;i++)cerr<<deg[i]<<' ';cerr<<endl;
	int l=0,r=0;
	for(int i=1;i<=n;i++)if(deg[i]==1)q[r++]=i;
	while(l<n-1)
	{
		int x=q[l++];vis[x]=1;
		// cerr<<"VIS: "<<x<<endl;
		for(int i=hd[x];i;i=ne[i])
		{
			int y=to[i];
			if(!vis[y])
			{
				// cerr<<"_DEG: "<<y<<endl;
				if(1==--deg[y])q[r++]=y;
				pa[x]=y;
			}
		}
	}
	// cerr<<"LR: "<<l<<' '<<r<<endl;
	assert(l==n-1&&r==n);
	pa[q[l]]=0;//root
	// for(int i=1;i<=n;i++)cerr<<pa[i]<<' ';cerr<<endl;
	l=-1,r=n;
	while(l<r-1)
	{
		int mid=l+r>>1;
		if(chk(mid))r=mid;
		else l=mid;
	}
	return r;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	int c=rd(),T=rd();
	while(T--)cout<<slv()<<'\n';
}