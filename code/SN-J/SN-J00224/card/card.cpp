#include<bits/stdc++.h>
using namespace std;
int ans[30010];
int a[50010];
int n,m;
deque<int> dq;
struct note
{
	int n,i;
};
note vis[30010];
void mem()
{
	for(int i=1;i<=m;i++)
	{
		vis[i]={0,0};
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		mem();
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]].n==0)
			{
				dq.push_back(a[j]);
				vis[a[j]].n++;
				vis[a[j]].i=j;
			}
			else
			{
				while(true)
				{
					if(dq.back()==a[j])
					{
						break;
					}
					else
					{
						vis[dq.back()].n--;
						dq.pop_back();
					}
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j].n==1)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
