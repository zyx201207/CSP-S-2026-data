#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],dis[5005],vis[5005],ptime,Ans,cnt[5005];
vector<int> v[5005];
int check(int x)
{
	int l=1,r=x,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[x]-a[mid]<=d)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
priority_queue<pair<int,int> >p;
void dist(int x)
{
	for(int i=1;i<=n;i++) dis[i]=1e18;
	while(p.size()) p.pop();
	ptime++;
	dis[x]=0;
	p.push({0,x});
	while(p.size())
	{
		int o=p.top().second;
		p.pop();
		vis[o]=ptime;
		for(auto i:v[o])
		{
			if(vis[i]==ptime) continue;
			if(dis[i]>dis[o]+1)
			{
				dis[i]=dis[o]+1;
				p.push({-dis[i],i});
			}
		}
	}
}
void siz(int x)
{
	cnt[x]++;
	if(cnt[x]>=3) return;
	for(auto i:v[x])
	{
		if(dis[i]==dis[x]+1)
		{
			siz(i);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		Ans=0;
		for(int i=1;i<=n;i++)
		{
			int id=check(i);
			for(int j=id;j<=i-1;j++)
			{
				v[i].push_back(j);
			}
			dist(i);
			for(int j=1;j<=i-1;j++) cnt[j]=0;
			siz(i);
			for(int j=1;j<=i-1;j++)
			{
				if(cnt[j]==2) Ans++;
			}
		}
		cout<<Ans<<endl;
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}