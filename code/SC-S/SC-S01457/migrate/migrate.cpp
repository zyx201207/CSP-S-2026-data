#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
#define endl '\n'
using namespace std;
int C,T,N,D,A[2000005],dis[200005],cnt[200005];
struct Node
{
	int u,dis;
};
void bfs(int st)
{
	queue<Node> Q;
	Q.push({st,0});
	while(!Q.empty())
	{
		int u=Q.front().u,ds=Q.front().dis;Q.pop();
		if(ds>dis[u])
		{
			continue;
		}
		if(ds<dis[u])
		{
			cnt[u]=1;dis[u]=ds;
		}
		else
		{
			cnt[u]++;
		}
		int x=lower_bound(A+1,A+N+1,A[u]+D)-A;
		if(A[x]!=A[u]+D)
		{
			x--;
		}
		for(int v=u+1;v<=x;v++)
		{
			Q.push({v,ds+1});
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>N>>D;
		for(int i=1;i<=N;i++)
		{
			cin>>A[i];
		}
		if(C<=10)
		{
			int ans=0;
			for(int i=1;i<N;i++)
			{
				for(int j=i;j<=N;j++)
				{
					dis[j]=1e18;
					cnt[j]=0;
				}
				bfs(i);
				for(int j=i+1;j<=N;j++)
				{
					if(cnt[j]==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
/*
Name: 
Copyright: 
Author: The Pioneer,The Concluder 
Date: 18/08/26 10:10
Description: 
*/