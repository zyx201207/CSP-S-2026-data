#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mi=1e9;
int w[200005];
vector<int> v[200005];
bool vis[200005],f;
int k[505];
int a[505][500005];
int t[505][500005];
int x[100005];
int y[100005];
inline void dfs(int id,int time,int mb)
{
	if(id==mb)
	{
		//cout<<time<<' ';
		mi=min(time,mi);
		return ;
	}
	for(int i=0;i<v[id].size();i++)
	{
		int lzl=v[id][i];
		
		//time+=t[lzl][id];
		
		//cout<<lzl<<' '<<id<<' '<<t[lzl][id]<<endl;
		//cout<<time<<endl;
		for(int j=1;j<=k[lzl];j++)
		{
			if(vis[a[lzl][j]]==0)
			{
				vis[a[lzl][j]]=1;
				//cout<<lzl<<' '<<a[lzl][j]<<' '<<time<<endl;
				dfs(a[lzl][j],time+t[lzl][a[lzl][j]]+t[lzl][id],mb);
				vis[a[lzl][j]]=0;
			}
		}
		
	}
	
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][a[i][j]]);
			//cout<<i<<' '<<a[i][j]<<' '<<t[i][a[i][j]]<<endl;
			v[a[i][j]].push_back(i); 
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		mi=1e9;
		vis[x[i]]=1;
		dfs(x[i],w[x[i]],y[i]);
		cout<<mi+w[y[i]]<<endl;
	}
    return 0;
}
