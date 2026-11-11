#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m,d,q;
int w[500010];
int k[510];
vector<int> a[510],t[510];
int x,y;
unordered_map<int,int> mp;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i)
		w[i]=read();
	for(int i=1;i<=n;++i)
	{
		k[i]=read();
		for(int j=1;j<=k[i];++j)
		{
			int xx=read(),yy=read();
			a[i].push_back(xx),t[i].push_back(yy),mp[xx]=i;
		}
	}
	for(int sbyyy=1;sbyyy<=q;++sbyyy)
	{
		x=read(),y=read();
		int ans=0;
		ans+=w[mp[x]]+w[mp[y]]+t[mp[x]][mp[x]]+t[mp[y]][mp[y]];
		cout<<ans<<'\n';
	}
	return 0;
}