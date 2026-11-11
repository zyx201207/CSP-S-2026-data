#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,x,y;
const int MAXM = 500005;
const int MAXN = 505; 
const int MAXP = 666;
const long long INF = 1e18; 
long long w[MAXM],k[MAXN];
long long a,t,ans;
//long long a[MAXN][20005];//怕空间爆 
//long long t[MAXN][20005];//怕空间爆 
long long dis[MAXP][MAXP];
int station[MAXM][25];
long long stime[MAXM][25];

//BF floyd
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>c>>n>>m>>d>>q;
	
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i != j) dis[i][j] = INF;
		else dis[i][j] = 0; 
	}
	
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin>>a>>t;
			station[a][0]++;
			station[a][station[a][0]] = i;
			stime[a][station[a][0]] = t;

		}//找到每个站有哪些线路经过
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=station[i][0];j++)
		for(int k=1;k<=station[i][0];k++)
		{
			
			if(j!=k)
			dis[station[i][j]][station[i][k]] = min(dis[station[i][j]][station[i][k]] , 
			stime[i][j] + stime[i][k]);
			//if(i==2 and j == 1 and k == 2) cout<<"ahhhhh "<<stime[i][j]<<" "<<stime[i][k]<<endl;
		}
	}
	
//	for(int i=1;i<=m;i++)
//	{
//		cout<<i<<" ";
//		for(int j=0;j<=station[i][0];j++)
//		cout<<stime[i][j]<<" ";
//		cout<<endl;
//	}



//	cout<<"***"<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
//	cout<<"***"<<endl;
	 
	//以上为找到任意两条线路之间的最短时间，检查无误
	//floyd
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	} //FloydNotCut
	
	 
//	cout<<"***"<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
//	cout<<"***"<<endl;
	
	while(q--)
	{
		cin>>x>>y;
		ans = INF;
		for(int i=1;i<=station[x][0];i++)
		for(int j=1;j<=station[y][0];j++)
		{
			ans = min(ans , w[x] + w[y] + 
			dis[station[x][i]][station[y][j]] + 
			stime[x][i] + stime[y][j]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
