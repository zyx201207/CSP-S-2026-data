#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000002],b[2000002],cnt,ans,w[2000002],siz[2000002],dep[2000002],pre[2000002],fa[2000002],tt[2000002],ff[200002];
int sl[2000002],sr[2000002],vis[2000002];
vector<int> g[2000002];
int read()
{
	int f=0,x=0;char c=getchar();
	while(c<48||c>57){if(c=='-')f=1;c=getchar();}
	while(c>=48&&c<=57) x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return (f==1?-x:x);
}
void dfs(int x)
{
	siz[x]=1;
	for(int y:g[x])
	{
		dep[y]=dep[x]+1;
		dfs(y);
		siz[x]+=siz[y];
	}
}
void solve(int ll,int rr)
{
	map<pair<int,int>,bool> mp;
	cnt=0;dep[1]=1;
	for(int i=ll;i<=rr;i++) b[++cnt]=a[i];
	if(cnt<=3) return;
	int l=cnt,r=0;
	for(int i=1;i<=cnt;i++) g[i].clear(),tt[i]=0,vis[i]=0;
	for(int i=cnt;i>=2;i--)
	{
		while(l>1&&b[l-1]+d>=b[i]) l--;
		g[l].push_back(i);
		fa[i]=l;
//		cout<<i<<" "<<l<<"\n";
	}
	r=1;
	for(int i=1;i<=cnt;i++)
	{
		while(r<cnt&&b[i]+d>=b[r+1]) r++;
		mp[{r,i}]=mp[{i,r}]=1;
	}
	dfs(1);
//	for(int i=1;i<=cnt;i++) pre[i]=pre[i-1]+dep[i];
	l=1;r=0;
	for(int i=2;i<=cnt;i++)
	{
		while(l<=i-1&&b[l]<b[i]-d) l++;
		if(i==cnt) r=i-1;
		else
		{
			while(r<i-1&&b[r+1]<b[i+1]-d) r++;
		}
		sl[i-1]=l;sr[i-1]=r;
		for(int j=l;j<=r;j++) tt[j]=i;
//		w[i-1]=max(0ll,pre[r]-pre[l-1]);
//		cout<<i<<":"<<l<<" "<<r<<"\n";
	}
	for(int i=2;i<=cnt;i++)
		if(tt[fa[i]]==tt[i]) dep[fa[i]]=0;
	for(int i=1;i<=cnt;i++) pre[i]=pre[i-1]+dep[i];
	l=1;r=0;
	for(int i=2;i<=cnt;i++)
	{
		while(l<=i-1&&b[l]<b[i]-d) l++;
		if(i==cnt) r=i-1;
		else
		{
			while(r<i-1&&b[r+1]<b[i+1]-d) r++;
		}
		w[i-1]=max(0ll,pre[r]-pre[l-1]);
	}
	for(int i=1;i<cnt;i++)
	{
		int s=siz[i]-1,ss=0;
		for(int j=sl[i];j<=sr[i];j++)
		{
			int now=j;//cout<<i<<" "<<j<<"\n";
			while(vis[now]!=i&&now)
			{
				vis[now]=i;ss++;
				if(!mp[{now,fa[now]}]) break;
				now=fa[now];
			}
		}
		for(int j:g[i])
		{
			if(i+1==j) s-=siz[j];
	//		cout<<i<<" "<<j<<"\n";
		}		
		ans+=s*ss;
	//	cout<<i<<" "<<s<<" "<<w[i]<<"\n";
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		int lst=1;
		for(int i=1;i<=n;i++)
			if(i==n||a[i]+d<a[i+1])
			{
				solve(lst,i);
				lst=i+1;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
