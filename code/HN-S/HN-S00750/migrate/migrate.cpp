#include<bits/stdc++.h>
#define int long long
using namespace std;
int z[2000010];
int cnt[2000010];
int minn[2000010];
bool f[2000010];
int n,d;
void bfs(int x)
{
	queue<pair<int,int> >q;
	q.push({x,0});
	f[x]=1;
	while(!q.empty())
	{
		int a=q.front().first,b=q.front().second;
//		cout<<a<<" "<<b<<endl;
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(i==a||abs(z[i]-z[a])>d)
			{
				continue;
			}
			if(f[i]!=0)
			{
				if(minn[i]>b+1)
				{
					minn[i]=b+1;
					cnt[i]=1;
				}
				else if(minn[i]==b+1)
				{
					cnt[i]++;
				}
			}
			else
			{
				f[i]=1;
				minn[i]=b+1;
				cnt[i]=1;
				q.push({i,b+1});
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>z[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				memset(minn,0,sizeof(minn));
				memset(cnt,0,sizeof(cnt));
				memset(f,0,sizeof(f));
				bfs(i);
				for(int j=1;j<=n;j++)
				{
					if(cnt[j]==2&&i!=j)
					{
						ans++;
					}
				}
			}
			cout<<ans/2<<endl;
		}
	}
	else if(c<=12)
	{
		while(t--)
		{
			int t1,t2,tt;
			cin>>n>>d>>t1>>t2;
			for(int i=3;i<=n;i++)
			{
				cin>>tt;
			}
			int t=d/(t2-t1),ans=0;
			for(int i=1;i<t;i++)
			{
				ans+=i*(n-i);
			}
			cout<<ans/2<<endl;
		}
	}
}

