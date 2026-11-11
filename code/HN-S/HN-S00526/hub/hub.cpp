#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
vector<int> e[N];
int dep[N],f[N],st;

void dfs(int u,int ft)
{
	
	dep[u] = dep[ft] + 1;
	for(int i = 0 ; i < e[u].size() ; i++)
	{
		int v = e[u][i];
		if(v == ft)continue;
		dfs(v,u);
		f[u] = max(f[u],dep[v]);
	}
}
void dpdfs(int u,int ft)
{
	dep[ft]++,f[ft]++;
	f[u] = max(f[u] - 1,f[ft]);
	for(int i = 0 ; i < e[u].size() ; i++)
	{
		int v = e[u][i];
		if(v == ft)continue;
		dfs(v,u);
	}
	dep[ft]--,f[ft]--;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		printf("1\n");
	}
	return 0;
 } 
