#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int q,n,c;
long long d;
vector<long long> v;
vector<vector<int>> tu;
queue<int> qu;
vector<vector<int>> dis,cnt;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>q;
	while(q--)
	{
		cin>>n>>d;
		v.resize(n+1);
		tu.resize(n+1);
		dis.resize(n+1,vector<int>(n+1,-1));
		cnt.resize(n+1,vector<int>(n+1));
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;v[j]-v[i]<=d && j<=n;j++)
			{
				tu[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			dis[i][i]=0;
			cnt[i][i]=1;
			qu.push(i);
			while(!qu.empty())
			{
				int f=qu.front();
				qu.pop();
				for(auto j:tu[f])
				{
					if(dis[i][f]+1==dis[i][j]) cnt[i][j]+=cnt[i][f];
					else if(dis[i][j]==-1)
					{
						dis[i][j]=dis[i][f]+1;
						cnt[i][j]=cnt[i][f];
						qu.push(j);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<'\n';
		tu.clear();
		v.clear();
		dis.clear();
		cnt.clear();
	}
	return 0;
}
