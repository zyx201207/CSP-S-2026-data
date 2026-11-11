#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
const int N=1e5+5;
struct SegT
{
	int l,r,id;
}tr[N<<2];
int a[N],dis[N],cnt[N],tot;
vector<pair<int,int>>g[N];
void build(int p,int l,int r)
{
	tr[p]={l,r};
	if(l==r)
	{
		tr[p].id=l;
		return;
	}
	tr[p].id=++tot;
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	g[tr[p].id].push_back({tr[ls].id,0});
	g[tr[p].id].push_back({tr[rs].id,0});
}
void addedge(int p,int l,int r,int id)
{
	if(tr[p].l>=l&&tr[p].r<=r)
	{
		g[id].push_back({tr[p].id,1});
		return;
	}
	if(l<=tr[ls].r)addedge(ls,l,r,id);
	if(r>=tr[rs].l)addedge(rs,l,r,id);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n,d,cur=1,ans=0;cin>>n>>d;
		for(int i=1;i<=tot;i++)g[i].clear();
		for(int i=1;i<=n;i++)cin>>a[i];
		tot=n;
		build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			while(cur<n&&a[cur+1]-a[i]<=d)cur++;
			if(i+1<=cur)addedge(1,i+1,cur,i);
		}
		for(int i=1;i<=n;i++)
		{
			deque<int>q;
			for(int i=1;i<=tot;i++)dis[i]=1e18,cnt[i]=0;
			q.push_front(i);
			dis[i]=0,cnt[i]=1;
			while(!q.empty())
			{
				int u=q.front();
				q.pop_front();
				for(auto it:g[u])
				{
					int v=it.first,w=it.second;
					if(!cnt[v])
					{
						dis[v]=dis[u]+w;
						cnt[v]=cnt[u];
						if(w==0)q.push_front(v);
						else q.push_back(v);
					}
					else if(dis[v]==dis[u]+w)cnt[v]+=cnt[u];
				}
			}
			for(int j=1;j<=n;j++)ans+=(cnt[j]==2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

*/