#include<bits/stdc++.h>
using namespace std;
long long c,m,d,n,q;
long long w[200007],a[507][200007],t[507][200007],qx[100007],qy[100007];
long long dist[500007],k[500007];
pair<long long,long long> point[500007][24];
long long ans;
void bfs(long long x,long long y)
{
	memset(dist,0x3f,sizeof(dist)),ans=0;
	
	queue<long long> q;dist[x]=0;
	q.push(x);
	while(!q.empty())
	{
		
		long long rust=q.front();
		q.pop();
		for(long long i=1;i<=point[rust][0].first;i++)
		{
//		cout<<point[rust][0].first;
		long long mini=0;
			long long de=point[rust][i].first;


				
//				cout<<mini<<" ";
				for(long long j=1;j<=k[point[rust][i].first];j++)
				{
					mini=t[point[rust][i].first][point[rust][i].second];
					if(a[point[rust][i].first][j]!=rust)
					{
//					cout<<1;	
						mini+=t[point[rust][i].first][j]+dist[rust];
//						cout<<mini<<" ";
						if(dist[a[point[rust][i].first][j]]>mini)
						{
							dist[a[point[rust][i].first][j]]=mini;
							q.push(a[point[rust][i].first][j]);
						}
					}					
				}
			
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			point[a[i][j]][++point[a[i][j]][0].first]={i,j};
		}
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>qx[i]>>qy[i];
		bfs(qx[i],qy[i]);
		ans=w[qx[i]]+w[qy[i]]+dist[qy[i]];
//		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
