#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y;
int mp[5050][5050],w[501010],k[501010],a[505][50100],t[505][51010],minn=INT_MAX,vis[501010];
vector<int> line[501010],id[501010];
void dfs(int now,int e,int ti,int s,int ss,int ee)
{
	if(ti+t[e][ee]+t[s][ss]>minn)
	{
		return;
	}
	if(now==e)
	{ 
		minn=min(minn,ti+t[e][ee]+t[s][ss]);
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(mp[now][i]!=0&&now!=i&&vis[i]==0)
			{
//				cout<<i<<"\n"; 
				vis[i]=1;
				dfs(i,e,ti+mp[now][i],s,ss,ee);
				vis[i]=0;
			}
		}
	}
}
signed main()
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			line[a[i][j]].push_back(i);
			id[a[i][j]].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int kk=1;kk<=k[i];kk++)
			{
				for(int l=1;l<=k[j];l++)
				{
					if(a[i][kk]==a[j][l])
					{
						if(mp[i][j]==0)
						{
							mp[i][j]=t[i][kk]+t[j][l];
						}
						else
						{
							mp[i][j]=min(mp[i][j],t[i][kk]+t[j][l]);
						}
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--)
	{
		cin>>x>>y;
		for(int i=0;i<line[x].size();i++)
		{
			for(int j=0;j<line[y].size();j++)
			{
//				cout<<id[x][i]<<" "<<id[y][j]<<"\n";
				dfs(line[x][i],line[y][j],0,line[x][i],id[x][i],id[y][j]);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
		minn=INT_MAX;
		vis[501010]={0};
	}
} 
