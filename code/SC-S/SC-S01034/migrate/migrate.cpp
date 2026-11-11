#include<bits/stdc++.h>
using namespace std;
#define int long long
char input[1<<20],*pf,*pe;
#define gc() (pf==pe&&(pe=(pf=input)+fread(input,1,1<<20,stdin),pf==pe)?EOF:*pf++)
int rdi()
{
	int n=0,k=1,c=gc();
	for(;!isdigit(c);c=gc())
	{
		if(c=='-')
		{
			k=-1;
		}
	}
	for(;isdigit(c);c=gc())
	{
		n=n*10+c-48;
	}
	return n*k;
}
const int N=2e6+35;
const int inf=1e18+35;
int x[N];
int nxt[N];
int g[N];
void solve()
{
	int n=rdi(),d=rdi();
	for(int i=1;i<=n;i++)
	{
		x[i]=rdi();
	}
	for(int i=1;i<=n;i++)
	{
		nxt[i]=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		nxt[i-1]=i;
		int p=i,q=i-1,l=i,r=i;
		while(r>=l||q>=p)
		{
			int np,nq,nl,nr;
			if(r<l)
			{
				nq=nxt[q];
				np=nxt[q-1]+1;
				nl=nq+1;
				nr=nq;
			}
			else if(r==l)
			{
				nr=nxt[r];
				nl=nxt[r-1]+1;
				np=nl;
				nq=nl-1;
			}
			else
			{
				nr=nxt[r];
				nl=nxt[r-1]+1;
				nq=nxt[r-1];
				np=nxt[r-2]+1;
			}
			if(nr<=r)
			{
				break;
			}
			if(nl<=r)
			{
				nl=r+1;
			}
			if(nq<=r)
			{
				nq=nl-1;
			}
			if(np<=r)
			{
				np=r+1;
			}
			ans+=nq-np+1;
			p=np;
			q=nq;
			l=nl;
			r=nr;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	int c=rdi(),t=rdi();
	int cc=c,cd=c;
	swap(cc,cd);
	for(int i=1;i<=t;i++)
	{
		solve();
	}
	return 0;
}
//lpy