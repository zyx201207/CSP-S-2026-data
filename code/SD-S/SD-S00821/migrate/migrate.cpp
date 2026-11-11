#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int inf=1e18,N=2e6+6;
int read()
{
	int x=0,fl=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-'){fl=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*fl;
}
int num[N],suf[N],pre[N],mxr[N],mnl[N],n,D;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();int T=read();
	while(T--)
	{
		n=read();D=read();
		for(int i=1;i<=n;i++)
			num[i]=read();
		int id=1;
		for(int i=1;i<=n;i++)
		{
			while(id+1<=n&&num[id+1]-num[i]<=D)id++;
			mxr[i]=id;
		}
		id=n;
		for(int i=n;i>=1;i--)
		{
			while(id-1>=1&&num[i]-num[id-1]<=D)id--;
			mnl[i]=id;
		}
		for(int i=n;i>=1;i--)
		{
			if(mxr[i]==i||mxr[i]==mxr[i-1])suf[i]=1;
			else suf[i]=suf[mxr[i]]+(mxr[i]-mxr[i-1]);
		}
		for(int i=1;i<=n;i++)
		{
			if(mnl[i]==i||mnl[i]==mnl[i+1])pre[i]=1;
			else pre[i]=pre[mnl[i]]+(mnl[i+1]-mnl[i]);
		}
		int ans=0;
		for(int i=2;i<n-1;i++)
		{
			if(mnl[i+1]>=i||mxr[i]<=i+1)continue;
			pii L={mnl[i+1],mnl[i+2]-1},R={mxr[i-1]+1,mxr[i]};
			int cntl=0,cntr=0;
			if(L.se<L.fi)cntl=0;
			else if(mnl[i]<L.fi)cntl=L.se-L.fi+1;
			else cntl=pre[L.fi]+(L.se-L.fi);
			if(R.se<R.fi)cntr=0;
			else if(mxr[i+1]>R.se)cntr=R.se-R.fi+1;
			else cntr=suf[R.se]+(R.se-R.fi);
			ans+=cntl*cntr;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
