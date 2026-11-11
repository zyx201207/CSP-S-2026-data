#include<bits/stdc++.h>
using namespace std;
const int N=5050;
const int INF=0x3f3f3f3f; 
int a[N];

int main()
{
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d,num=0;
		cin>>n>>d;
		vector<vector<int>>node(n+10,0);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					for(auto {x,y}:node[i])
					{
						if(j==x&&a[j]-a[i]>y)
							node[i].push_back({j,a[j]-a[i]});
						else
							continue;
					}
				}
				else
					break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int nm=0;
			queue<int>q;
			vector<int>dist(n+10,INF);
			q.push_back(a[i]);
			dist[a[i]]=0;
			while(q.size())
			{
				int v=q.top();
				q.pop();
				for(auto {x,y}:node[v])
				{
					if(dist[x]==dist[v]+y)
						nm++;
					dist[x]=min(dist[x],dist[v]+y);
				}
			}
			num+=nm;
		}
		cout<<num<<" ";
	}
	return 0;	
}
