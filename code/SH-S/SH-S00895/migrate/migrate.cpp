#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 301
ll c,t,n,a,lasta,l[N],d,nowp,nowl,ans;
int g[N][N][N];/*g[起点][终点][长度]*/
struct node{
	ll s,p,m;
}tmp;
queue<node> q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		lasta = ans = 0;
		scanf("%lld%lld",&n,&d);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%lld",&a);
			l[i-1] = a-lasta;
			lasta=a;
			q.push((node){i,i,0});
			for(int j = i+1 ; j <= n ; j++)
			{
				for(int k = 1 ; k <= j-i ; k++)
				{
					g[i][j][k] = 0;
				}
			}
		}
		while(!q.empty())
		{
			tmp=q.front();
			q.pop();
			g[tmp.s][tmp.p][tmp.m]++;
//			printf("g[%lld][%lld][%lld] = %lld\n",tmp.s,tmp.p,tmp.m,g[tmp.s][tmp.p][tmp.m]);
			nowp = tmp.p + 1;
			nowl = l[tmp.p];
			while(nowp <= n && nowl <= d)
			{
				q.push((node){tmp.s,nowp,tmp.m+1});
				nowl += l[nowp];
				nowp++;
			}
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i+1 ; j <= n ; j++)
			{
				for(int k = 1 ; k <= j-i ; k++)
				{
					if(g[i][j][k] == 2) ans++;
					if(g[i][j][k] != 0) break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

