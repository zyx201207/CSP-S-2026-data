#include<bits/stdc++.h>
using namespace std;
const int N=510;

int c,n,m,d,q;
int w[N],k[N];
int t[N][N],a[N][N];
int rout[N][N];//station -> routine
struct Node
{
	int step;
	int station;
	int routine;

};

int bfs(int s,int t)
{

	int ans=1e9+10;
	queue< Node >pq;
	for(int i=1;i<=k[s];i++)
	{
		pq.push({0,k[s],i});
	}
	while(!pq.empty())
	{
		int sta=pq.front().station,r=pq.front().routine,step=pq.front().step;
		if(sta==t){ans=min(ans,step);continue;}
        for(int i=1;i<=k[i];i++)
        {
            pq.push({step+1,r,sta});
        }



	}
    printf("%d\n",ans);


}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];//a i,j 表示第 i 条线路
			//经过的第 j 个地铁站,
			//t i,j表示从a i, j地铁站的站厅走到第 i 条线路的站台
			//需要的时间
			rout[a[i][j]][i]=t[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		int s,t;
		cin>>s>>t;
		ans+=w[s];
		ans+=w[t];
		bfs(s,t);
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
