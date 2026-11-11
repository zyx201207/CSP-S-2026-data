#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],y,t,sum,num,ant,maxx,cnt;
bool vis[200005];
void dfs(int k)
{
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			y=a[i];
			while(y)
			{
				t*=10;
				t+=y%2;
				y/=2;
			}
			ant=max(sum,t);
			sum=num;
			num=0;
			while(ant)
			{
				num*=10;
				if(!sum%10^t%10)
					num+=1;
				sum/=10,t/=10;
				ant/=10;
			}
			if(k==m)
			{
				maxx=max(maxx,num);
				return;
			}
			else
				dfs(k+1);
			vis[i]=0;
			num=0;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1);
	while(maxx)
	{
		cnt*=2;
		cnt+=maxx%10;
		maxx/=10;
	}
	printf("%lld",cnt);
	return 0;
}
