#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>


using namespace std;

const int N=2e6+100;

struct Node
{
	int x11;
	int x21;
	int x12;
	int x22;
}node[N];

long long x[N];

int nx[N];
int pre[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",x+i);
		}
		x[n+1]=2e18;
		x[0]=-2e18;
		int j=1;
		for(int i=1;i<=n;i++)
		{
			for(j;j<=n+1;j++)
			{
				if(x[j]<=x[i]+d);
				else
				{
					nx[i]=j-1;
					break;
				}
			}
//			cout<<nx[i]<<endl;
		}
		j=n;
		for(int i=n;i<=1;i--)
		{
			for(j;j>=0;j--)
			{
				if(x[i]<=x[j]+d);
				else
				{
					pre[i]=j+1;
					break;
				}
			}
		}
	}
	return 0;
}
