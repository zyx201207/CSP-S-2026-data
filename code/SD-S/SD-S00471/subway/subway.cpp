#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k,a,t,x,y,di2[M][N];
ll di[N][N],ans;
vector<pair<int,int>> b[M];
void work();
void output();
void input()
{
	memset(di,0x3f,sizeof(di));
	memset(di2,0x3f,sizeof(di2));
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>a>>t;
			b[a].push_back({i,t});
			di2[a][i]=min(di2[a][i],t);
		}
	}
}
void work()
{
	
	for (int i=0;i<=n;i++) di[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		for (auto j:b[i])
			for (auto k:b[i])
			{
				int a1=j.first,t1=j.second;
				int a2=k.first,t2=k.second;
				di[a1][a2]=min(di[a1][a2],(ll)t1+t2);
			}
	}
	/*for (int i=1;i<=m;i++)
	{
		for (auto j:b[i])
			cout<<j.first<<" ";
		cout<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<di[j][i]<<" ";
		cout<<endl;
	}*/
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int k=0;k<=n;k++)
			{
				//di[i][k]=min(di[i][k],di[i][j]+di[j][k]);
				di[j][k]=min(di[j][k],di[j][i]+di[i][k]);
				//di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
				//for (int l=0;l<=n;l++)
				//{
				//	di[j][k]=min(di[j][k],di[j][l]+di[l][k]);
				//}
			}
		}
	}
	
}
void output()
{
	/*
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<di2[j][i]<<" ";
		cout<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<di[i][j]<<" ";
		cout<<endl;
	}*/
	for (int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		for (auto j:b[x])
			for (auto k:b[y])
			{
				int a1=j.first,a2=k.first;
				ans=min(ans,di[a1][a2]+di2[x][a1]+di2[y][a2]);
			}
		ans+=w[x],ans+=w[y];
		cout<<ans<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	work();
	output();
	return 0;
}

