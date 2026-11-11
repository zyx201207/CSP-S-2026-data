#include<bits/stdc++.h>
using namespace std;
int c,n,m,dn,q;//dn->d
vector<int>v[55555];
vector<int>dis[55555];//distance
bool inq[55555];//whether it is in queue?
int w[55555];
int k[555];
int a[555][55555];
int t[555][55555];
int l[55555];//length
int start,aim;
int d[55522];//the first m subway dots;then n subway lines
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&dn,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			v[a[i][j]].push_back(m+i);
			dis[a[i][j]].push_back(t[i][j]);
			l[a[i][j]]++;
			v[m+i].push_back(a[i][j]);
			dis[m+i].push_back(t[i][j]);
			l[m+i]++;
			//cout<<a[i][j]<<' '<<m+i<<' '<<t[i][j]<<endl;
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&start,&aim);
		//cout<<i<<endl;
		for(int i=1;i<=n+m;i++)d[i]=INT_MAX;
		d[start]=0;
		queue<int> q;
		q.push(start);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			inq[u]=0;
			//cout<<u<<' '<<d[u]<<endl;
			if(d[u]>d[aim])continue;
			for(int i=0;i<l[u];i++)
			{
				int qu=v[u][i];
				int wi=dis[u][i];
				if(d[qu]>d[u]+wi)
				{
					d[qu]=d[u]+wi;
					if(!inq[qu])
					{
						q.push(qu);
						inq[qu]=1;
					}
				}
			}
		}
		printf("%d\n",d[aim]+w[start]+w[aim]);
	}
	return 0;
}
