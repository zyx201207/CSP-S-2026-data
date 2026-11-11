#include<bits/stdc++.h>
using namespace std;
int c,t,n[10001],d[10001],dy[1001][10001],sy[10001],cp,lj=999999999,an;


void dfs(int st,int en,int ma,int step)
{
	if(st==en)
	{
		if(step<lj)
		{
			lj=step;
			cp=0;
		}
		if(step==lj)
		{
			cp++;
		}
		return;
	}
	for(int i=1;i<=ma;i++)
	{
		if(st<en)
		{
			st+=i;
			dfs(st,en,ma,++step);
			step--;
			st-=i;
		}
	}
} 

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n[i];j++)
		{
			cin>>dy[i][j];
		} 
	} 
	for(int i=0;i<t;i++)
	{
		int g=n[i];
		for(int j=0;j<g;j++)
		{
			sy[j]=dy[i][j];
		} 
		for(int j=0;j<g;j++)
		{
			for(int z=j+1;z<=g;z++)
			{
				if(z-j>2)
				{
				dfs(j,z,d[i],0);
				if(cp==2)
				{
					an++;
				}
				cp=0;
				lj=999999999;
			}
			}
		}
		cout<<an<<endl;
		continue;
	} 
	return 0;
}

