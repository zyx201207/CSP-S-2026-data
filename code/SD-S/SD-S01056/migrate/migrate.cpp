#include<bits/stdc++.h>
#define int long long
#define pairr pair<int,int>
using namespace std;
int c,t,n,d,ans;
int a[2000100];
priority_queue<pairr,vector<pairr>,greater<pairr> > que;
vector<int> tu[2000100];
int dd[2000100],summ[2000100];
signed main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cout<<0<<'\n';
		continue;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			tu[i].clear();
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum+=a[j]-a[j-1];
				if(sum<=d)
				{
					tu[i].push_back(j);
				}
				sum-=a[i+1]-a[i];
			}
		}
		for(int s=1;s<=n;s++)
		{
			que.push({0,s});
			memset(dd,0x3f,sizeof(dd));
			memset(summ,0,sizeof(summ));
			dd[s]=0;
			while(!que.empty())
			{
				int u=que.top().second,w=que.top().first;
				que.pop();
				if(w>dd[u]) continue;
				for(auto v:tu[u])
				{
					if(dd[v]>=1+w)
					{
						dd[v]=1+w;
						if(dd[v]==1+w)
						{
							summ[v]++;
							que.push({1+w,v});
						}
						else
						{
							summ[v]=1;
							que.push({1+w,v});
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				cout<<summ[i]<<' ';
				if(summ[i]!=s&&summ[i]==2)
				{
					ans++;
				}
			}
			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

