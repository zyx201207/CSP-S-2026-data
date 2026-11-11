#include<bits/stdc++.h>
using namespace std;
#define int long long 

inline int read()
{
	int x(0);
	char ch(getchar());
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

const int N=(int)(5e5)+5;
class eg
{
public:
	int to,w;
};
class Node
{
public:
	int x,val;
	bool operator<(const Node& tmp)const
	{
		return val>tmp.val;
	}
};
int c,n,m,d,q,f[505][505],w[N];
vector<eg>nbr[N];

inline void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	return ;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k(read()),x,t;
		while(k--)
		{
			x=read(),t=read();
			nbr[x].push_back({i,t});
		}
		for(int j=1;j<=n;j++)
			f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(auto a:nbr[i])
			for(auto b:nbr[i])
				f[a.to][b.to]=min(f[a.to][b.to],a.w+b.w);
	floyd();
	while(q--)
	{
		int x(read()),y(read()),ans=1e18;
		for(auto a:nbr[x])
			for(auto b:nbr[y])
				ans=min(ans,f[a.to][b.to]+a.w+b.w);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}