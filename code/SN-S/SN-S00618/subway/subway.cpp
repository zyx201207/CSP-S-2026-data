#include<bits/stdc++.h>
using namespace std;
const int N=2500;
const int M=505;
const int T=200;
struct str{
	int xp;//站 
	int yp;//线 
};
int k[M];
int w[N];
int a[M][N];
int t[M][N];
int x[T],y[T];
int vis[M],sum[M];
vector<int>v[M];//一条线路上的站台 
vector<int>auv[M];//一个站台链接的所有线路 

int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	queue<str>s;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			v[i].push_back(a[i][j]);
			auv[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		s.push({x[i],0});
		vis[x[i]]=1;
		sum[x[i]]=w[x[i]]+w[y[i]];
		while(!s.empty())
		{
			str it=s.front();
			int it1=it.xp;
			int it2=it.yp;
			s.pop();
			if(it1==y[i])
			{
				cout<<sum[it1]+t[it2][it1]<<"\n";
				break;
			}
			
			for(int i=auv[it1][1])
				for(auto ir:v[iv])//枚举线路上的点 
				{
					if(vis[ir]==0)
					{
						vis[ir]=1;
						s.push({ir,iv});
						if()
					}
				}
				
			
		}
	}
	
	return 0;
}
