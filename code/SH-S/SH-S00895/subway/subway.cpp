#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1001
ll c,n,m,d,q,w[N],s,e,y,t[N],k[N],l[N][N],a[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1 ; i <= m ; i++)
	{
		l[i][i] = 0;
		for(int j = i+1 ; j <= m ; j++)
		{
			l[i][j] = l[j][i] = INT_MAX;
		}
	}
	for(int i = 1 ; i <= m ; i++) scanf("%lld",&w[i]);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld",&y);
		for(int j = 1 ; j <= y ; j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
			for(int k1 = 1 ; k1 < j ; k1++)
			{
				if(t[j] + t[k1] < l[a[j]][a[k1]])
				{
					l[a[j]][a[k1]] = l[a[k1]][a[j]] = t[j] + t[k1];
//						printf("l[%lld][%lld] -> %lld\n",a[j],a[k1],l[a[j]][a[k1]]);
				}
			}
		}
	}
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(i == j) continue;
			for(int k1 = 1 ; k1 <= m ; k1++)
			{
				if(i == k1 || j == k1) continue;
				if(l[i][k1] + l[j][k1] < l[i][j])
				{
					l[i][j] = l[j][i] = l[i][k1] + l[j][k1];
//						printf("l[%lld][%lld] -> %lld , %lld\n",i,j,l[i][j],k1);
				}
			}
		}
	}
	for(int i = 1 ; i <= q ; i++)
	{
		scanf("%lld%lld",&s,&e);
		printf("%lld\n",w[s]+w[e]+l[s][e]);
//			printf("%lld\n",l[s][e]);
	}
	return 0;
}

