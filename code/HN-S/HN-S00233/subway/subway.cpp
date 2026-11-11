#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,m,d,p,a[505][1005],t[505][1005],w[505],len[505],vis[505];
struct SS{
	int x,w;
};
vector<SS>g[505];
int bfs(int x,int y)
{
	queue<SS>q;
	q.push({x,0});
	vis[x]=1;
	while(q.size())
	{
		SS k=q.front();
		q.pop();
		
		if(a[k.x][y])
		{
			return k.w;
		}
		
		for(int i=0;i<g[k.x].size();i++)
		{
			
			SS l=g[k.x][i];
			if(vis[l.x]==0)
			{
				cout<<k.w<<" ";
				k.w+=l.w;
				//cout<<k.w<<" ";
				vis[l.x]=1;
				q.push({l.x,k.w});	
			}	
		} 
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		for(int j=1,x,tt;j<=len[i];j++)
		{
			cin>>x>>tt;
			a[i][x]=1;
			t[i][x]=tt;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[j][i]==a[k][i]&&a[j][i]==1)
				{
					g[j].push_back({k,t[j][i]+t[k][i]});
					g[k].push_back({j,t[j][i]+t[k][i]});
				}
			}
		}
	}
	while(p--)
	{
		int l,r,sum=0,x,y;
		cin>>l>>r;
		
		for(int i=1;i<=n;i++)
		{
			if(a[i][l]==1) 
			{
				x=i;
				break;
			}
		}
			
		for(int j=1;j<=n;j++)
		{
		//	cout<<a[j][r]<<" ";
			if(a[j][r]) 
			{
				y=j;
				break;
			}
				
		}
			
		//cout<<endl;
		sum+=w[l]+w[r]+t[x][l]+t[y][r];
		int f=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][r]==1&&a[i][l]==1)
				f=1;
		}
		if(f==1)
			cout<<sum<<endl;
		else
			cout<<(sum+bfs(x,r))<<endl;
	//	cout<<sum<<" "<<w[l]<<" "<<w[r]<<" "<<t[x][l]<<" "<<t[y][r]<<" "<<y<<" "<<r<<endl;
		
	}
	return 0;
 } 
