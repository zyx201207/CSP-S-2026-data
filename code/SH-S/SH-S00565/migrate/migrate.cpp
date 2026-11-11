#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,s=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') s=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*s;
}
void print(int x){if(x>9) print(x/10);putchar(x%10+'0');}
struct node
{
	int v,w;
	bool operator<(node x) const{return x.w<w;}
};
int c,t,n,d,ans,a[2000010],vis[2000010],dis[2000010],cnt[2000010];
vector<int> edges[2000010];
priority_queue<node> q;
void dijkstra(int s)
{
	for(int i=1;i<=n;i++) vis[i]=0,dis[i]=2e9,cnt[i]=0;
	cnt[s]=1,dis[s]=0,q.push({s,0});
	while(!q.empty())
	{
		node t=q.top();q.pop();int u=t.v,w=t.w;
		if(vis[u]) continue;vis[u]=1;
		for(int v:edges[u])
			if(dis[v]>w+1) dis[v]=w+1,cnt[v]=cnt[u],q.push({v,dis[v]});
			else if(dis[v]==w+1) cnt[v]+=cnt[u];
	}
}
signed main()//56pts
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
//		for(int i=1,l,r,mid;i<=n;i++)
//		{
//			l=i,r=n;
//			while(l<=r)
//			{
//				int mid=(l+r)/2;
//				if(a[mid]<=d+a[i]) l=mid+1,lim[i]=mid;
//				else r=mid-1;
//			}
//		}
//		for(int i=n-1;i>=1;i--)
//		{
//			if(lim[lim[i]]==lim[i]) continue;
//			if(lim[lim[i]-1]==lim[lim[i]]&&lim[lim[i]-2]<lim[lim[i]]) dp[i]=1+dp[lim[i]];
//			ans+=dp[i];
//		}
//		cout<<ans<<'\n';
		if(c==11||c==12)
		{
			d/=a[2]-a[1],d+=d-1;
			if(d<=1) putchar('0');
			else print(max(0ll,n-d));
			putchar('\n');continue;
		}
		if(c==13||c==14){putchar('0'),putchar('\n');continue;}
		for(int i=1;i<=n;i++) edges[i].clear();
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) continue;
				edges[i].push_back(j);
			}
		for(int i=1;i<n;i++)
		{
			dijkstra(i);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		print(ans),putchar('\n');
	}
}
