#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long num,step;
	bool friend operator < (node a,node b)
	{
		return a.step>b.step;
	}
};
priority_queue<node> q;
int C,T;
long long a[2000010];
long long dis[2000010];
long long n,d;
long long num[2000010];
long long ans=0;
//long long dp[2000010];
void dj(int x)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e18;
		num[i]=0;
	}
	q.push({x,0});
	dis[x]=0;
	while(q.size())
	{
		node s=q.top();
		q.pop();
		for(int v=1;v<=n;v++)
		{
			if(a[v]-a[s.num]>d)
			{
				continue;
			}
			if(s.step+1<dis[v])
			{
				dis[v]=s.step+1;
				num[v]=1;
				q.push({v,dis[v]});
			}
			else if(s.step+1==dis[v])
			{
				num[v]++;
				q.push({v,dis[v]});
			}
		}
	}
//	cout<<x<<"---:\n";
	for(int i=1;i<=n;i++)
	{
//		cout<<num[i]<<" ";
		if(num[i]==2)
		{
			ans++;
		}
	}
//	cout<<"\n";
	return;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(C<=10)
	{
		while(T--)
		{
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
//			for(int i=1;i<=n;i++)
//			{
//				for(int j=i+1;j<=n;j++)
//				{
//					if(a[j]-a[i]<=d)
//					{
//						cout<<i<<" "<<j<<"\n";
//					}
//				}
//			}
			//找出每个点的最短路
			for(int i=1;i<=n;i++)
			{
				dj(i);
			}
			cout<<ans<<"\n";
		}
	}
	else if(C>=11&&C<=12)//等差数列
	{
		while(T--)
		{
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			long long num=a[2]-a[1];
			if(num*2ll>d)
			{
				cout<<0<<"\n";
				continue;
			}
			int flag=d/num;
			int len=flag+1+flag-1;
//			cout<<len<<"----\n";
			for(int i=1;i+len-1<=n;i++)
			{
				ans++;
//				cout<<i<<" "<<i+len-1<<"----\n";
			}
			cout<<ans<<"\n";
		}
	}
	else if(C>=13&&C<=14)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(int i=1;i<=n;i++)
			{
				int flag=upper_bound(a+i,a+n+1,a[i]+d)-a;
				int flag2=upper_bound(a+i,a+n+1,a[i]+2*d)-a;
				ans+=flag2-flag;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
