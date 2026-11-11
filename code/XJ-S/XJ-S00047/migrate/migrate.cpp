#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c, n, m, d, q;
int w[N] 
int k[N]
int f[N]
int t[M][M]

int dist[N]
vector<pii>gv[M];
vector<pii>ge[M];

int get_f(int x)
{
	if (x!=f[x])f[x]=get_f(f[x]);
	return f[x];
} 
int main()
{
	reopen("migrate .in","r"stdin)  
	reopen("migrate .out","w"stdout) 
	scanf ("%d%d%d%d%d",&c,&n,%m,&d,&q);
	for(int i = 1,i <= m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i = 1,i <= m;i++)
	{
		f[i] = i;
	} 
	for(int i = 1,i <= n;i++) 
	{
		scanf("%d",&k[i]);
	}
	for(int j = 1,j <=k[i] ;j++)
	{
		int U,W;
		scanf("%d",&f[i]);
	}
	for(int j = 1,j <=n[i] ;j++)
	{
		scanf("%d",&t[i]);
	}

	cout << scanf;
	return 0;
} 

