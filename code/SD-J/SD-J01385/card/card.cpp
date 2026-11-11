#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
const int M = 3e5+10;

int n,m;
int a[N];
int ans[M];
deque<int> q;

signed main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool flag=false;
			//q.push_back(a[j]);
			int s=q.size();
			for(int k=0;k<q.size();k++)
			{
				int x=q.front();
				if(x==a[j])
				{
					flag=true;
					for(int l=0;l<s-k;l++)
					{
						q.pop_front();
					}
				}
				if(flag)
				{
					//q.pop_front();
					//q.push_back(a[j]);
					break;
				}
				q.pop_front();
				q.push_back(x);
			}
			q.push_back(a[j]);
		}
		int s=q.size();
		for(int k=0;k<s;k++)
		{
			ans[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++)
	{
		//cout<<ans[i]<<' ';
		printf("%d ",ans[i]);
	}
	return 0;
}
