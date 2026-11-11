#include<bits/stdc++.h>
using namespace std;
int n,k,f[100005],vis[100005],dis[100005],anss,dis2[100005];
queue<int>q;
vector<int>v[100005];
int Find(int x)
{
	if(x==f[x]) return x;
	return f[x]=Find(f[x]);
}
void dfs(int x,int fa)
{
	dis[x]=dis2[x]=f[x]=0;
	for(auto i:v[x])
	{
		if(i!=fa)
		{
			dfs(i,x);
			if(dis[x]<dis[i]+1)
			{
				dis2[x]=dis[x];
				dis[x]=dis[i]+1;
			}
			else dis2[x]=max(dis2[x],dis[i]+1);
			f[x]=max(f[x],f[i]);
		}
	}
	f[x]=max(f[x],dis2[x]+dis[x]);
}
void dfs2(int x,int fa,int wmx,int wmx2)
{
	if(x!=1)
	{
		anss=min(anss,max((f[x]+1)/2,(wmx2+2)/2));
	}
	wmx2=max(wmx2,wmx);
	int mx1=n+1,mx2=0,mx3=0,mxx1=n+1,mxx2=0;
	dis[n+1]=wmx;
	f[n+1]=wmx2;
	for(auto i:v[x])
	{
		if(i!=fa)
		{
			if(dis[mx1]<dis[i])
			{
				mx3=mx2;
				mx2=mx1;
				mx1=i;
			}
			else if(!mx2)
			{
				mx2=i;
			}
			else if(dis[mx2]<dis[i])
			{
				mx3=mx2;
				mx2=i;
			}
			else if(!mx3) mx3=i;
			else if(dis[mx3]<dis[i]) mx3=i;
			if(f[mxx1]<f[i])
			{
				mxx2=mxx1;
				mxx1=i;
			}
			else if(!mxx2) mxx2=i;
			else if(f[mxx2]<f[i]) mxx2=i;
		}
	}
	for(auto i:v[x])
	{
		if(i!=fa)
		{
			int sum1=0,sum2=0;
			if(i!=mx1)
			{
				sum1=dis[mx1]+1;
			}
			else sum1=dis[mx2]+1;
			if(i!=mxx1)
			{
				sum2=f[mxx1];
				if(i!=mx1&&i!=mx2)
				{
					sum2=max(sum2,dis[mx1]+dis[mx2]);
				}
				else if(i==mx1)
				{
					sum2=max(sum2,dis[mx3]+dis[mx2]);
				}
				else
				{
					sum2=max(sum2,dis[mx1]+dis[mx3]);
				}
			}
			else
			{
				sum2=f[mxx2];
				if(i!=mx1&&i!=mx2)
				{
					sum2=max(sum2,dis[mx1]+dis[mx2]);
				}
				else if(i==mx1)
				{
					sum2=max(sum2,dis[mx3]+dis[mx2]);
				}
				else
				{
					sum2=max(sum2,dis[mx1]+dis[mx3]);
				}
			}
			dfs2(i,x,sum1,sum2);
			dis[n+1]=wmx;
			f[n+1]=wmx2;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(c==13||c==14)
		{
			if(n==k) cout<<0<<'\n';
			else cout<<max(1,((n+1)/2-k+2+3)/4)<<'\n';
			continue;
		}
		if(c<=3)
		{
			int ans=1e9;
			for(int i=1;i<(1<<n);i++)
			{
				int tot=0;
				for(int j=1;j<=n;j++)
				{
					if((1<<(j-1))&i)
					{
						tot++;
						vis[j]=1;
					}
					else vis[j]=0;
					f[j]=j;
				}
				if(tot!=k) continue;
				for(int j=1;j<=n;j++)
				{
					for(auto kk:v[j])
					{
						if(vis[j]&&vis[kk]&&Find(j)!=Find(kk)) f[Find(j)]=Find(kk);
					}
				}
				tot=0;
				for(int j=1;j<=n;j++)
				{
					if(Find(j)==j&&vis[j]) tot++;
				}
				if(tot>2) continue;
				for(int j=1;j<=n;j++)
				{
					if(vis[j]) q.push(j),dis[j]=1;
					else dis[j]=0;
				}
				int mx=0;
				while(!q.empty())
				{
					int x=q.front();
					q.pop();
					for(auto j:v[x])
					{
						if(!dis[j])
						{
							dis[j]=dis[x]+1;
							mx=max(mx,dis[j]);
							q.push(j);
						}
					}
				}
				ans=min(ans,mx-1);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c==7||c==11||c==12)
		{
			dfs(1,0);
			anss=1e9;
			dfs2(1,0,0,0);
			cout<<anss<<'\n';
		}
	}
	return 0;
}
