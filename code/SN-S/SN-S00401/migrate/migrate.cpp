#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
vector<long long> edge[N],come[N];
long long cnt[N];
long long c,t,n,d;
long long len;
void go(long long w,long long fa)
{
	if(edge[fa][w]==len)
	{
		cnt[w]++;
	}
	for(long long i=0;i<come[w].size();i++)
	{
		len++;
		go(come[w][i],fa);
		len--;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			edge[i].clear();
			come[i].clear();
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					come[i].push_back(j);
				}
			}
		}
		for(long long i=n;i>=1;i--)
		{
			long long w;
			if(a[i]+d>=a[n])
			{
				w=n;
			}
			else
			{
				w=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			}
			for(long long j=0;j<=i;j++)
			{
				edge[i].push_back(0);
			}
			for(long long j=i+1;j<=w;j++)
			{
				edge[i].push_back(1);
			}
			for(long long j=w+1;j<=n;j++)
			{
				edge[i].push_back(edge[w][j]+1);
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				cnt[j]=0;
			}
			len=0;
			go(i,i);
			for(long long j=i+1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
