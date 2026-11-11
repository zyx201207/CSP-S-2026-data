#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long dist[50010],d,cnt[50010],a[50010],sol;
vector<int>e[50010];
void bfs(int st)
{
	memset(dist,-1,sizeof dist);
	queue<int>q; 
	dist[st]=0;
	q.push(st);
	cnt[st]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<e[x].size();i++)
		{
			if(dist[e[x][i]]==-1)
			{
				q.push(e[x][i]);
				cnt[e[x][i]]+=cnt[x];
				dist[e[x][i]]=dist[x]+1;
			}
			else if(dist[e[x][i]]!=-1&&dist[e[x][i]]==dist[x]+1)
			{
				cnt[e[x][i]]+=cnt[x];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					e[i].push_back(j);
				}
				else
				{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cnt[j]=0;
			}
			bfs(i);		
			for(int j=1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					sol++;
				}
			}
		} 
		cout<<sol<<"\n";
		sol=0;
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
		}
	}
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
