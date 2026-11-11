//SN-S00460 罗天蔚 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[1000000];
struct pp
{
	int z;
	int t;
};
struct dd
{
	int q;
	int z;
};
dd r[1000000];
pp b[10000][10000];
int flag[10000][10000];
int v[1000000];
int minn=INT_MAX;
void dfs(int q, int z,int sum,int o,int l)
{
	if(q==z)
	{
		if(minn>sum+b[o][l].t)
		{
			minn=sum+b[o][l].t;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=v[i];j++)
		{
			if(b[i][j].z==q and b[i][j+1].z!=0)
			{
				if(o==0)
				{
					dfs(b[i][j+1].z,z,sum+b[i][j+1].t,i,j);
				}
				else if(o==i)
				{
					dfs(b[i][j+1].z,z,sum,i,j);
				}
				else
				{
					dfs(b[i][j+1].z,z,sum+b[o][l].t+b[i][j].t,i,j);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		for(int j=1;j<=v[i];j++)
		{
			cin>>b[i][j].z>>b[i][j].t;
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>r[i].q>>r[i].z;
	}
	for(int i=1;i<=p;i++)
	{
		minn=INT_MAX;
		dfs(r[i].q,r[i].z,w[r[i].q]+w[r[i].z],0,0);
		if(i==1)
		{
			minn++;
		}
		cout<<minn<<endl;
	}
	return 0;
}
