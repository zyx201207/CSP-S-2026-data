#include<bits/stdc++.h>
using namespace std;
const int K=5010;
int c,t;
int n;
long long d;
long long a[K];
vector<int>G[K];
queue<int>q;
int cnt[K];
int dis[K];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=i;j>0;j--)
			{
				if(a[i]-a[j]>d) break;
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			q.push(i);
			memset(cnt,0,sizeof(cnt));
			memset(dis,0x3f,sizeof(dis));
			dis[i]=0;
			while(!q.empty())
			{
				int T=q.front();
				q.pop();
				cnt[T]++;
				for(auto &it:G[T])
				{
					if(dis[it]<dis[T]+1) continue;
					dis[it]=dis[T]+1;
					q.push(it);
				}
			}
			for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
