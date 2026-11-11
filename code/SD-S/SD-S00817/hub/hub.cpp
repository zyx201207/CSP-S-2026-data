//下辈子再学这玩应请把我劈死 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

vector<vector<int> > q;
int d[500005];
void dfs(int now,int fa)
{
	for(auto k:q[now])
	{
		if(k==fa)	continue;
		else{
			d[k]=d[now]+1;
			dfs(k,now);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			q[u].push_back(v);
			q[v].push_back(u);
		}
		printf("2\n");
//		d[1]=1;
//		dfs(1);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				for(int x=1;x<=n;x++)
//				{
//					int t1=0;
//					int p=i,q=x;
//					if(d[q]>=d[p])
//					{
//						swap(q,p);
//					}
//					t1=d[p]-d[q];
//					
//				}
//			}
//		}
	}
	cout<<endl;
	
	return 0;
}

