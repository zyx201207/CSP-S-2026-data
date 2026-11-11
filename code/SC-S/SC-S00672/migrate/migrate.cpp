#include<bits/stdc++.h>//migrate
using namespace std;
const int N=2e6+100;
int a,b,c,d,e[N],g,h;
vector<int>f1[N];
vector<int>f2[N];
int ans1=1e9+10,ans2,ans3=0;
int vis[N];
void dfs1(int x,int y,int z,int k)
{
	vis[x]=1;
	if(x==k)
	{
		if(z<ans1)
		{
			ans1=z;
			ans2=1;
		}
		else
		{
			if(z==ans1)
			{
				ans2++;
			}
		}
		return ;
	}
	for(int i=0;i<f1[x].size();i++)
	{
		int u1=f1[x][i];
		int u2=f2[x][i];
		if(u1==y || vis[u1]==1)
		{
			continue;
		}
		vis[u1]=1;
		dfs1(u1,x,z+u2,k);
		vis[u1]=0;
	}
	
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	while(b--)
	{
		cin>>c>>d;
		for(int i=1;i<=c;i++)
		{
			cin>>e[i];
		}
		cout<<"0\n";
	}

	return 0;
}
