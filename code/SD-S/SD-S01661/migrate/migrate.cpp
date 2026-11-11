#include<bits/stdc++.h>
using namespace std;
#define NN 5010
#define N 2000010
#define LL long long
int c,T,n,g[NN],mxr[N];
LL d,ans,a[N];
inline LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		f=(c=='-')?-1:f,c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
inline void solve()
{
	n=read(),d=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
		mxr[i]=0;
	for(int i=1;i<=n;++i)
	{
		int l=i,r=n,res=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]-a[i]<=d)
				res=mid,l=mid+1;
			else r=mid-1;
		}
		mxr[i]=res;
	}
	if(c<=10)
	{
		for(int i=1;i<=n;++i)
		{
			queue<int> q;
			int st=i;q.push(i);
			for(int j=1;j<=n;++j) g[j]=0;
			g[i]=1;
			while(!q.empty())
			{
				const int l=q.size();
				int nst=st;
				for(int i=1;i<=l;++i)
				{
					int tp=q.front();q.pop();
					nst=max(nst,mxr[tp]);
					for(int j=max(st+1,tp+1);j<=mxr[tp];++j)
						g[j]=min(3,g[j]+g[tp]);
				}
				for(int i=st+1;i<=nst;++i)
					q.push(i);
				st=nst;
			}
			for(int j=i+1;j<=n;++j)
				if(g[j]==2) ++ans;
		}
		printf("%lld\n",ans),ans=0;
	}
	else if(c>=11&&c<=12)
	{
		if(mxr[1]==1)
		{
			printf("0\n");
			return ;
		}
		for(int i=1;i<=n;++i)
		{
			int x=mxr[i];
			if(mxr[x]!=mxr[x-1]) ++ans;
		}
		printf("%lld\n",ans),ans=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)
		solve();
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
