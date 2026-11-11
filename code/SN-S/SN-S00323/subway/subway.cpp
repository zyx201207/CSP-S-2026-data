//孙正轩  陕西省西安中学  SN-S00323 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005];
struct per{
	int v,w;
};
struct perq{
	int v,w;
};
bool operator<(perq a,perq b)
{
	return a.w>b.w;
}
vector <per> G[500005];
vector <int> a[505];
vector <int> t[505];
int ans[105][500005];
void djs(int s,int pos)
{
	priority_queue <perq> q;
	q.push({s,0});
	ans[pos][s]=0;
	while(!q.empty())
	{
		perq u=q.top();
		q.pop();
		if(u.w>ans[pos][u.v]) continue;
		for(int i=0;i<G[u.v].size();i++)
		{
			per v1=G[u.v][i];
			if(ans[pos][v1.v]>u.w+v1.w)
			{
				ans[pos][v1.v]=u.w+v1.w;
				q.push({v1.v,ans[pos][v1.v]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[pos][i]+=w[s]+w[i]+2*t[1][1];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0X3f,sizeof ans);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int aij,tij;
			cin>>aij>>tij;
			a[i].push_back(aij);
			t[i].push_back(tij);
		}
		for(int u=0;u<a[i].size();u++)
			for(int j=0;j<a[i].size();j++)
			{
				int v1=a[i][j];
				if(a[i][u]!=v1) G[u].push_back({v1,t[i][u]});
			}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x<=100&&ans[x][y]<0X3f)
			cout<<ans[x][y]<<endl;
		else if(y<=100&&ans[y][x]<0X3f)
			cout<<ans[y][x]<<endl;
		else if(x<=100)
		{
			djs(x,x);
			cout<<ans[x][y]<<endl;
		}
		else if(y<=100)
		{
			djs(y,y);
			cout<<ans[y][x]<<endl;
		}
		else
		{
			djs(x,101);
			cout<<ans[101][y]<<endl;
		}
			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
