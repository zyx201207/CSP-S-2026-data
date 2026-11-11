#include<bits/stdc++.h>
using namespace std;
int const N=505,inf=0x3f3f3f3f,M=5e5+5;
long long f[N][N];
int c,n,m,d,q;
long long ans=inf;
struct sta{
	int exit;
	int to_train[N];
	vector<int>pass;
}dot[M];
//c, n, m, d, q，测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，出行计划数
long long llmin(long long m1,long long m2)
{
	if(m1>m2)return m2;
	return m1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>dot[i].exit;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=i==j?0:inf;
		}
	}
	//地铁口到站厅
	for(int i=1;i<=n;i++)
	{
		int k;//第 i 条线路经过的站数 
		cin>>k; 
		for(int j=1;j<=k;j++) 
		{
			int ain,b;
			cin>>ain>>b;
			dot[ain].to_train[i]=b;
			dot[ain].pass.push_back(i);
			if(i>1)
			{
				for(int p=0;p<(int)dot[ain].pass.size();p++)
				{
					int to_line=dot[ain].pass[p];
					f[i][to_line]=llmin((long long)dot[ain].to_train[i]+dot[ain].to_train[to_line],f[i][to_line]);
					f[to_line][i]=f[i][to_line];
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]==inf||f[k][j]==inf)continue;
				f[i][j]=min(f[i][j],(long long)f[i][k]+f[k][j]); 
			}
		}
	} 
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ans=inf;
		long long inout=0;
		int passx=(int)dot[x].pass.size();
		int passy=(int)dot[y].pass.size();
		if(passx==1&&passy==1)
		{
			inout=(long long)dot[x].to_train[dot[x].pass[0]]+dot[y].to_train[dot[y].pass[0]];
		}
		for(int i=0;i<passx;i++)
		{
			for(int j=0;j<passy;j++)
			{
				int xline=dot[x].pass[i];
				int yline=dot[y].pass[j];
				if(ans>f[xline][yline])
				{
					ans=f[xline][yline];
					inout=(long long)dot[x].to_train[xline]+dot[y].to_train[yline];
				}
			}
		}
		ans+=(long long)dot[x].exit+dot[y].exit;
		cout<<ans+inout<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
