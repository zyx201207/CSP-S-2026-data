#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int,int>::iterator it;
map <int,int> mp[1000001];

struct Pr
{
	int first;
	int second;
	Pr():first(0),second(0){}
};
vector <int> a[1000001];
int id_ln[1000001][2];//id in line
bool in_ln[1000001];//in line
bool added[1000001];
int fa[1000001];
int s[1000001];
int zjl,zjlca,zjr,zjlen;//zhijing:l->lca->r = len
int k;

inline int read()
{
	int op = 1;
	int rsum = 0;
	char ch = getchar();
	while(ch != '-'&&(ch < '0'||ch > '9'))
	{
		ch = getchar();
	}
	while(ch == '-')
	{
		ch = getchar(),op = -op;
	}
	while(ch >= '0'&&ch <= '9')
	{
		rsum = rsum*10+(ch-'0'),ch = getchar();
	}
	return rsum*op;
}

Pr dfs(int t)
{
	Pr maxn;
	maxn.first = 0;
	maxn.second = t;
	for(int i = 0;i < a[t].size();i++)
	{
		int u = a[t][i];
		if(fa[u] == 0)
		{
			fa[u] = t;
			Pr tmp = dfs(u);
			if(maxn.first+tmp.first+1 > zjlen)
			{
				zjlen = maxn.first+tmp.first+1;
				zjl = maxn.second;
				zjlca = t;
				zjr = tmp.second;
			}
			if(maxn.first < tmp.first)
			{
				maxn = tmp;
			}
		}
	}
	maxn.first++;
	return maxn;
}

int dfs_add(int t,int fi,bool flag)
{
	added[t] = true;
	int maxn_dep = 0;
	for(int i = 0;i < a[t].size();i++)
	{
		int u = a[t][i];
		if((flag == false&&fa[u] == t)||(flag == true&&added[u] == false))
		{
			maxn_dep = max(maxn_dep,dfs_add(u,fi,flag)+1);
		}
	}
	mp[fi][-maxn_dep]++;
	return maxn_dep;
}

bool check(int m)
{
	s[0] = 0;
	for(int i = 1;i <= zjlen;i++)
	{
		s[i] = s[i-1];
		for(it = mp[i].begin();it != mp[i].end();it++)
		{
			int dist = -(it->first);
			int cnt = it->second;
			if(dist >= m)
			{
				s[i] += cnt;
			}
			else
			{
				break;
			}
		}
	}
	int sum = 0;
	for(int i = m+1;i <= zjlen;i++)
	{
		sum++;
		int tsum = sum+s[i];
		int r = zjlen-m;
		for(int j = i+1;j <= zjlen;j++)
		{
			int tmp;
			if(mp[j].begin() == mp[j].end())
			{
				tmp = -1;
			}
			else
			{
				tmp = -((mp[j].begin())->first);
			}
			if(j-i+tmp+1 <= m)
			{
				continue;
			}
			r = min(r,j+max(0ll,m-tmp-1));
			if(r <= j)
			{
				break;
			}
		}
		tsum += max(0ll,zjlen-m-r+1);
		tsum += s[zjlen]-s[r-1];
		if(tsum <= k)
		{
			return true;
		}
	}
	return false;
}

void lll()
{
	int n;
	n = read();
	k = read();
	
	//init
	zjl = zjlca = zjr = zjlen = 0;
	for(int i = 1;i <= n;i++)
	{
		a[i].clear();
		fa[i] = 0;
		in_ln[i] = false;
		mp[i].clear();
		added[i] = false;
	}
	
	for(int i = 1;i < n;i++)
	{
		int u,v;
		u = read();
		v = read();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	fa[1] = -1;
	dfs(1);
	
//	printf("%lld %lld %lld\n",zjl,zjlca,zjr);
	
	//change into line
	int cur = 0;
	for(int i = zjl;i != zjlca;i = fa[i])
	{
		in_ln[i] = true;
		added[i] = true;
		id_ln[++cur][0] = i;
		id_ln[i][1] = cur;
	}
	in_ln[zjlca] = true;
	added[zjlca] = true;
	id_ln[++cur][0] = zjlca;
	id_ln[zjlca][1] = cur;
	cur = zjlen+1;
	for(int i = zjr;i != zjlca;i = fa[i])
	{
		in_ln[i] = true;
		added[i] = true;
		id_ln[--cur][0] = i;
		id_ln[i][1] = cur;
	}
	for(int i = 2;i <= n;i++)
	{
		if(in_ln[i] == false&&in_ln[fa[i]] == true)
		{
			dfs_add(i,id_ln[fa[i]][1],false);
		}
	}
	if(fa[zjlca] != -1)
	{
		dfs_add(fa[zjlca],id_ln[zjlca][1],true);
	}
	
//	for(int i = 1;i <= zjlen;i++)
//	{
//		printf("%lld:",id_ln[i][0]);
//		for(it = mp[i].begin();it != mp[i].end();it++)
//		{
//			printf("%lld,%lld ",-(it->first),it->second);
//		}
//		printf(" ");
//	}
//	printf("\n");
//	printf("start erfen\n");
	
	int l = 0;
	int r = zjlen/2-1;
	int ans = zjlen/2;
	while(l <= r)
	{
		int mid = (l+r)/2;
		
//		printf("%lld ",mid);
		
		if(check(mid))
		{
			r = mid-1;
			ans = mid;
			
//			printf("%lld true\n",mid);
		}
		else
		{
			l = mid+1;
			
//			printf("%lld false\n",mid);
		}
	}
	printf("%lld\n",ans);
}

#undef int
int main()
{
#define int long long
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	c = read();
	t = read();
	while(t--)
	{
		lll();
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
