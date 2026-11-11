#include<bits/stdc++.h>
using namespace std;

int c,q;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	for(int k111=1;k111<=q;k111++)
	{
		int n,d;
		cin>>n>>d;
		int a[n+7];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				queue<int> q[2];
				int vis[n+7];
				memset(vis,0,sizeof(vis));
				q[0].push(j);
				q[1].push(0);
				vector<int> ansss;
				while(q[1].size()!=0)
				{
					int x=q[0].front();
					int y=q[1].front();
					q[0].pop();
					q[1].pop();
					vis[x]=1;
					if(x==i)
					{
						ansss.push_back(y);
						continue;
					}
					if(x==i)
					{
						continue;
					}
					for(int m=x;m<=i;m++)
					{
						if(a[x]+d<a[m])
						{
							break;
						}
						else
						{
							if(x>=m)
							{
								continue;
							}
								q[0].push(m);
								q[1].push(y+1);
							
							
						}
					}
				}
				int zx=n;
				for(int m=0;m<=ansss.size()-1;m++)
				{
					if(ansss[m]<zx)
					{
						zx=ansss[m];
					}
				}
				for(int m=0;m<=ansss.size()-1;m++)
				{
					if(ansss[m]==zx)
					{
						ans++;
					}
				}
				ans--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
