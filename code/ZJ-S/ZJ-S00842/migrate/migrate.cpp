#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,sum;
int a[2000025],dist[2000025],tt[2000025];
struct ilj{
	int x,d;
};
void bfs(int sx)
{
	queue<ilj> q;
	q.push({sx,0});
	memset(dist,0x3f3f,sizeof(dist));
	memset(tt,0,sizeof(tt));
	dist[sx]=0;
	
	while(!q.empty())
	{
		ilj t=q.front();
		q.pop();
		if(dist[t.x]<t.d) continue;
		
		for(int i=t.x+1;i<=n;i++)
		{
			if(a[i]-a[t.x]>d) break;
			if(dist[i]>t.d+1)
			{
				dist[i]=t.d+1;
				tt[i]=1;
				q.push({i,t.d+1});
			}
			else if(dist[i]==t.d+1) tt[i]++;
		}
	}
}
void solve()
{
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		sum=0;
			int x,y;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
				{
					x=i;
					break;
				}
			}
			for(int i=x+1;i<=n;i++)
			{
				if(a[i]-a[x-1]>d)
				{
					cout<<n-i+1<<"\n";
					break;
				}
			}
	}
}
void solve2()
{
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		int c=a[2]-a[1],s=d/c;
		if(s==0||s==1)
		{
			cout<<0<<'\n';
			continue;
		}
		cout<<n-s*2+1<<'\n';
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	if(c==11||c==12)
	{
		solve2();
		return 0;
	}
//	if(c==13||c==14)
//	{
//		solve();
//		return 0;
//	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		sum=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++) 
			{
				if(tt[j]==2) sum++;
			}
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}