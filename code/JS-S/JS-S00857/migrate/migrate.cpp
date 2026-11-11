#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> PII;
const int N=2e6+100;
long long c,t,n,d,a[N],cnt=0;
bool vis[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		map<long long,long long> mp;
		for(int i=1;i<=n;i++)mp[a[i]]=i;
		for(int i=1;i<n-2;i++)
		{
			for(int j=2;j<=d;j++)
			{
				if(mp[a[i]+j]-i-1>0)
				{
					int sx=i,ex=mp[a[i]+j];
					cnt=0;
					queue<PII> q;
					memset(vis,false,sizeof(vis));
					q.push({sx,0});
					vis[sx]=1;
					while(!q.empty())
					{
						PII head=q.front();
						q.pop();
						if(head.first==ex)
						{
							cnt++;
							if(cnt>2)break;
						}
						for(int k=1;k<=d;k++)
						{
							if(mp[a[head.first]+k])q.push({mp[a[head.first]+k],head.second+1});
						}
					}
					if(cnt==2)ans++;
				}
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
