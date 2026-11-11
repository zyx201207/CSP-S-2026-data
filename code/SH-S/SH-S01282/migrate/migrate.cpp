#include <bits/stdc++.h>
using namespace std;
int v[100005];
long long cnt,ce,n,q,j,d;
vector<int> a[10005];
int dao[100005];
void dfs(int x,int sum)
{
	v[x]++;
	if (v[x]==2) cnt++;
	if(v[x]>2) cnt--;
	for (int i=0;i<=a[x].size();i++)
	{
		int nx=x+a[x][i];
		cout<<nx;
		dfs(nx,sum++);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ce>>q;
	while(q--)
	{
		cnt=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>dao[i];
		}
		for (int i=1;i<=n;i++)
		{
			while(dao[j]-dao[i]<=d)
			{
				a[i].push_back(dao[j]); 
			}
		}
		dfs(0,0);
		cout<<cnt;
	}
	return 0;
}
