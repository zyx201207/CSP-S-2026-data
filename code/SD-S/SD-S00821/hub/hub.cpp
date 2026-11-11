#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int inf=1e9,N=1e6+6;
int read()
{
	int x=0,fl=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-'){fl=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*fl;
}
int he[N],ne[N<<1],t[N<<1],tot;
int n,m,fl[N],fa[N],dep[N],mxd[N],K,p[N];
void add(int x,int y)
{
	ne[++tot]=he[x];
	he[x]=tot;
	t[tot]=y;
	return ;
}
void dfs(int x)
{
	for(int i=he[x];i;i=ne[i])
	{
		int y=t[i];
		if(y==fa[x])continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		dfs(y);
	}
	return ;
}
void dfsd(int x)
{
//	cout<<x<<' ';
	for(int i=he[x];i;i=ne[i])
	{
		int y=t[i];
		if(fl[y])continue;
		fl[y]=1;
		dfsd(y);
		mxd[x]=max(mxd[y]+1,mxd[x]);
	}
}
int check(int k) 
{
	pii L,R;
	int Cnt=0;
	L={k+1,k+1};R={K-k,K-k};
	int ll=k+2,rr=K-k-1,len=1;
	while(ll<=rr)
	{
		len++;
		if(min(mxd[p[ll]]+ll-L.se,mxd[p[ll]]+R.fi-ll)>k)
		{
			L.se=min(ll-(k-mxd[p[ll]]),ll);
			while(ll<=rr&&ll+1<=L.se+len)
			{
				if(min(mxd[p[ll]]+ll-L.se,mxd[p[ll]]+R.fi-ll)>k)
					L.se=min(ll-(k-mxd[p[ll]]),ll);
				ll++;
			}
		}
		if(min(mxd[p[rr]]+rr-L.se,mxd[p[rr]]+R.fi-rr)>k)
		{
			R.fi=max(rr+(k-mxd[p[rr]]),rr);
			while(ll<=rr&&rr-1>=R.fi-len)
			{
				if(min(mxd[p[rr]]+rr-L.se,mxd[p[rr]]+R.fi-rr)>k)
					R.fi=max(rr+(k-mxd[p[rr]]),rr);
				rr--;
			}
		}
		ll++;rr--;
	}
	Cnt+=L.se-L.fi+1+R.se-R.fi+1;
	for(int i=1;i<=n;i++)
		if(mxd[i]>=k&&fl[i]==1)
			Cnt++;
//	cout<<k<<':'<<Cnt<<'\n';
	return Cnt<=m;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();int T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=1;i<n;i++)
		{
			int x=read(),y=read();
			add(x,y);
			add(y,x);
		}
		dep[1]=fa[1]=0;
		dfs(1);
		int A=0;
		for(int i=1;i<=n;i++)
			if(dep[i]>dep[A])
				A=i;
		dep[A]=fa[A]=0;
		dfs(A);
		int B=0;
		for(int i=1;i<=n;i++)
			if(dep[i]>dep[B])
				B=i;
		int x=B;K=0;
		while(x)
		{
			fl[x]=2;
			p[++K]=x;
			x=fa[x];
		}
		for(int i=1;i<=K;i++)
			dfsd(p[i]);
		int l=0,r=K/2-1,ans=K/2-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
			{
				ans=mid; 
				r=mid-1;
			}
			else
				l=mid+1;
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			fl[i]=mxd[i]=0;
			he[i]=0;
		}
		tot=0;
	}
	return 0;
}
