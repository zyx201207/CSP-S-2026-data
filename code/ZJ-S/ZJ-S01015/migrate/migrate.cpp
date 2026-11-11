#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000010];
void ans1()
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int num=0,minn=0;
			queue<pair<int,int> > q;
			q.push({i,0});
			while(!q.empty())
			{
				int q1=q.front().first;
				int q2=q.front().second;
				q.pop();
				if(minn!=0 && q2>minn)
				{
					break;
				}
				if(q1==j)
				{
					if(minn==0)
					{
						minn=q2;
						num++;
					}
					else
					{
						num++;
					}
				}
				else
				{
					for(int mm=q1+1;mm<=j;mm++)
					{
						if(x[mm]-x[q1]>d)
						{
							break;
						}
						q.push({mm,q2+1});
					}
				}
			}
			if(num==2)
			{
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		if(1<=c && c<=10)
		{
			ans1();
		}
	}
	return 0;
}
