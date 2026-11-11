#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1001
ll c,t,n,f[N],l[N][N],maxm,minm,ansnum,u,v,k,p,s[N],ltk;
vector<int> es[N];
bool b,us[N],vis[N];
void dfs(ll x)
{
	vis[x] = 1;
	for(int i = 0 ; i < es[x].size() ; i++)
	{
		if(!vis[es[x][i]])
		{
			f[es[x][i]] = x;
			dfs(es[x][i]);
		}
	}
	vis[x] = 0;
}
void e(ll d,ll la)
{
	if(d == k+1)
	{
		ltk = 0;
		for(int i = 1 ; i <= k ; i++)
		{
			b = 1;
			for(int j = 1 ; j <= k ; j++)
			{
				if(l[s[i]][s[j]] == 1)
				{
					b = 0;
					break;
				}
			}
			if(b) ltk++;
			if(ltk == 3) break;
		}
		if(ltk >= 3) return;
		maxm = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(us[i]) continue;
			minm = INT_MAX;
			for(int j = 1 ; j <= k ; j++)
			{
				if(i != j && l[i][s[j]] < minm) minm = l[i][s[j]];
			}
			maxm = max(maxm,minm);
		}
		if(maxm < ansnum)
		{
			ansnum = maxm;
//			for(int i = 1 ; i <= k ; i++) printf("s[%lld]=%lld\n",i,s[i]);
//			printf("\nans->%lld\n\n",ansnum);
		}
		return;
	}
	for(int i = la+1 ; i <= n ; i++)
	{
		if(us[i] == 0)
		{
			us[i] = 1;
			s[d] = i;
			e(d+1,i);
			s[d] = 0; 
			us[i] = 0;
		}
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ansnum = 0;
		scanf("%lld%lld",&n,&k);
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i+1 ; j <= n ; j++)
			{
				l[i][j] = l[j][i] = 0;
			}
		}
		for(int i = 1 ; i < n ; i++)
		{
			scanf("%lld%lld",&u,&v);
			es[u].push_back(v);
			es[v].push_back(u);
			l[u][v] = l[v][u] = 1;
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(i == j) continue;
				for(int k1 = 1 ; k1 <= n ; k1++)
				{
					if(i == k1 || j == k1) continue;
					if(l[i][k1] != 0 && l[j][k1] != 0 && (l[i][k1]+l[j][k1] < l[i][j] || l[i][j] == 0)) l[i][j] = l[j][i] = l[i][k1]+l[j][k1];
				}
			}
		}
		dfs(1);
		ansnum = INT_MAX;
		e(1,0);
		printf("%lld\n",ansnum);
	}
	return 0;
}

