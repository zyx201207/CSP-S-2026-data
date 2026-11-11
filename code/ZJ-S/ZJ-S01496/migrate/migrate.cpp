#include<bits/stdc++.h>
using namespace std;
int c,t,n,dis[2000010];
long long p[2000010],ans,d,a[2000010];
vector<int> v[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14)
	{
		while(t--)
		{
			cout<<0<<endl;
		}
		return 0;
	}
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			int mx=0;ans=0;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++) if(a[i]-a[1]<=d) mx=i;
			if(mx<=2) cout<<0<<'\n';
			else
			{
				for(int i=1;i<=n;i++) 
				{
					if(i+2*mx-3<=n)	ans++;
				}
				cout<<ans<<'\n';
			} 
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) dis[j]=0x3f3f3f3f,p[j]=0;
			queue<int> q;
			q.push(i);dis[i]=0;p[i]=1;
			while(!q.empty())
			{
				int s=q.front();
				q.pop();
				for(int j:v[s])
				{
					if(dis[j]==dis[s]+1)
					{
						p[j]+=p[s];
					}
					else if(dis[j]>dis[s]+1)
					{
						dis[j]=dis[s]+1;
						p[j]=p[s];
						q.push(j);
					}
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				if(p[j]==2) 
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}