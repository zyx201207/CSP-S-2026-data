#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,D,ans,a[N];
bool st[N];
vector<int>g[N];
struct node{
	long long dep,step;
}res[N];
queue<int>qe;
void solve()
{
	cin>>n>>D;
	ans=0;
	for (int i=0;i<N;i++)g[i].clear();
	if (n<=5005)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			for (int j=i-1;j>0;j--)
			{
				if (a[i]-a[j]>D)break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		queue<int>q;
		for (int i=1;i<=n;i++)
		{
			for (int l=1;l<=n;l++)res[l].dep=0,res[l].step=0;
			memset(st,0,sizeof st);
			q=qe;
			q.push(i);
			st[i]=1;
			res[i].step=1;
			while(q.size())
			{
				int u=q.front();
				q.pop();
				for (int j=0;j<g[u].size();j++)
				{
					int v=g[u][j];
					if (st[v])
					{
						if (res[v].dep==res[u].dep+1)
						{
							res[v].step+=res[u].step;
						}
						continue;
					}
					res[v].dep=res[u].dep+1;
					res[v].step=res[u].step;
					q.push(v);
					st[v]=1;
				}
			}
			for (int j=1;j<=n;j++)
			{
				if (res[j].step==2)ans++;
			}
		}
	}
	cout<<ans/2<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
