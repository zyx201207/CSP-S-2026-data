#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[2000005],d,dis[2000005],cnt[2000005],n;
vector<int>eg[2000005];
queue<int>q;
void dfs(int st)
{
	dis[st]=0;cnt[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:eg[u])
		{
			if(dis[u]+1<dis[v]) 
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) 
		{
			int l=1,r=i-1,ansl=i,ansr=i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(x[i]-x[mid]<=d) ansl=mid,r=mid-1;
				else l=mid+1;
			}
			l=i+1,r=n;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(x[mid]-x[i]<=d) ansr=mid,l=mid+1;
				else r=mid-1;
			}
			for(int j=ansl;j<=ansr;j++) eg[i].push_back(j);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) dis[j]=1e9,cnt[j]=0;
			dfs(i);
//			for(int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n";
			for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans/2<<"\n";
		for(int i=1;i<=n;i++) eg[i].clear();
	}
	return 0;
}
