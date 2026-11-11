#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
int c,T,n,k,cnt[1000005],cnt1[1000005],num,maxx[1000005],vis[1000005],ma,count1;
vector<int>g[1000005];
void dfs(int k)
{
	int tag=0;
	for(int i=0;i<g[k].size();i++)
	{
		int v=g[k][i];
		if(!vis[v]&&cnt1[v]==2&&tag==0)//it's a line
		  count1++,ma=max(ma,count1),vis[v]=1,tag=1,dfs(v);
		else if(!vis[v]&&cnt1[v]==2)
		  count1=1,ma=max(ma,count1),vis[v]=1,dfs(v);
		else if(cnt1[v]==3)
		  count1=0,dfs(v);
	}
}
bool check(int dep)
{
	num=0,ma=0;
	memset(vis,0,sizeof(vis));
	queue<pii>q;
	int p;
	for(int i=1;i<=n;i++)cout<<cnt[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cnt1[i]=cnt[i];
		if(cnt[i]==1)q.push({i,dep+1});
	}
	while(!q.empty())
	{
		pii x=q.front();
		q.pop();
		int u=x.first,w=x.second;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(w>=2&&cnt1[v])
			{
				cnt1[v]--;
				cnt1[u]--;
				maxx[v]=max(maxx[v],w-1);
				if(cnt1[v]==1)q.push({v,maxx[v]});
			}
		}
	}
	//step 1 from bottom delete well done!
//	int numb=0,del=0,maxxx=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(cnt1[i])numb++;
//		if(cnt1[i]==1)p=i;
//		else vis[i]=1;
//		maxxx=max(maxxx,cnt1[i]);
//	}
//	if(numb<=k)return 1;//1
//	else del=numb-k;
//	
//	
//	
//	if(maxxx<=2)//we can delete to 2 points 
//	{
//		if(numb-2<=dep*2-1)return 1;
//		return 0;
//	}
//	dfs(p);
	if(ma<=dep*2-1)return 1;
	return 0;

}
void solve()
{
	memset(cnt,0,sizeof(cnt));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  g[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		cnt[u]++,cnt[v]++;
	}
	int l=1,r=n/2+1;
//	cout<<check(1)<<endl;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<'\n';
	return ;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
