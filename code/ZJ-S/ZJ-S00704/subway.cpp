#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[514514],sub[600],vis[600][600],vis1[600][600],st1[514514],distan[600][600];
bool flag[600][600];
struct road
{
	long long t,len;
}st[514514][22];
vector<road> sub1[600],sub2[600];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>sub[i];
		for(int j=1;j<=sub[i];j++)
		{
			long long fl,fl1;
			cin>>fl;
			cin>>fl1;
			sub1[i].push_back((road){fl,fl1});
			st[fl][st1[fl]++]=(road){i,fl1};
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<sub1[i].size();j++)
		{
			long long fl=sub1[i][j].t;
			long long fl1=sub1[i][j].len;
			for(int k=0;k<st1[fl];k++)
			if(st[fl][k].t!=i){
				long long dis=st[fl][k].len+fl1;
				if(vis[i][st[fl][k].t])
				{
					if(dis>vis1[i][st[fl][k].t])continue;
					vis1[i][st[fl][k].t]=dis;
					sub2[i][vis[i][st[fl][k].t]].len=dis;
				}
				sub2[i].push_back((road){st[fl][k].t,dis});
				vis[i][st[fl][k].t]=sub2[i].size()-1;
				vis1[i][st[fl][k].t]=dis;
			}
		}
	}
	memset(distan,0x3f,sizeof(distan));
	for(int i=1;i<=n;i++)
	{
		priority_queue<pair<long long,int> > q;
		q.push((pair<long long,int>){0,i});
		distan[i][i]=0;
		while(1)
		{
			while((!q.empty())&&flag[i][q.top().second]) q.pop();
			if(q.empty()) break;
			int h=q.top().second;
			flag[i][h]=1;
			q.pop();
			for(int j=0;j<sub2[h].size();j++)
			if((!flag[i][sub2[h][j].t])&&sub2[h][j].len+distan[i][h]<distan[i][sub2[h][j].t]){
				distan[i][sub2[h][j].t]=sub2[h][j].len+distan[i][h];
				q.push((pair<long long,int>){-distan[i][sub2[h][j].t],sub2[h][j].t});
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{	
//		for(int j=1;j<=n;j++)
//		{
//			cout<<distan[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--)
	{
		long long xx,yy,ans=1e18;
		cin>>xx>>yy;
		for(int i=0;i<st1[xx];i++)
		{
			for(int j=0;j<st1[yy];j++)
			{
				long long ans1=st[xx][i].len+st[yy][j].len+distan[st[xx][i].t][st[yy][j].t];
				ans=min(ans1,ans);
			}
		}
		cout<<ans+w[xx]+w[yy]<<'\n';
	}
	return 0;
}


