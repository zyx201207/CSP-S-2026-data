#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[50005],f[500009],ans[1005][1005],ab[500005][2];
vector<int> v[501][1003][2];
void dfs(int x){
	for(int i=0;i<v[x/(m+1)][x%(m+1)][0].size();i++)
	{
		if(f[v[x/(m+1)][x%(m+1)][0][i]]==-1 || f[v[x/(m+1)][x%(m+1)][0][i]]>v[x/(m+1)][x%(m+1)][1][i]+f[x])
		{
			f[v[x/(m+1)][x%(m+1)][0][i]]=v[x/(m+1)][x%(m+1)][1][i]+f[x];
			dfs(v[x/(m+1)][x%(m+1)][0][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c==20||c==21)
	{
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int a,t;
				cin>>a>>t;
				ab[a][i-1]=t;
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			long long ans2=2e9;
			if(ab[x][0]>0&&ab[y][0]>0)ans2=min(ans2,ab[x][0]+ab[y][0]);
			if(ab[x][1]>0&&ab[y][1]>0)ans2=min(ans2,ab[x][1]+ab[y][1]);
			for(int i=1;i<=m;i++)
			{
				if(ab[i][0]>0&&ab[i][1]>0&&i!=x&&i!=y)
				{
					if(ab[x][0]>0&&ab[y][1]>0)ans2=min(ans2,ab[x][0]+ab[y][1]+ab[i][0]+ab[i][1]);
					if(ab[x][1]>0&&ab[y][0]>0)ans2=min(ans2,ab[x][1]+ab[y][0]+ab[i][0]+ab[i][1]);
				}
			}
			cout<<ans2+w[x]+w[y]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k,las=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			v[i][a][0].push_back(a);
			v[i][a][1].push_back(t);
			v[0][a][0].push_back(i*(m+1)+a);
			v[0][a][1].push_back(t);
			if(las!=0)
			{
				v[i][a][0].push_back(i*(m+1)+las);
				v[i][a][1].push_back(0);
				v[i][las][0].push_back(i*(m+1)+a);
				v[i][las][1].push_back(0);
			}
			las=a;
		}
	}
	for(int k=1;k<=q;k++)
	{
		int x,y;
		cin>>x>>y;
		if(ans[x][y]>0)cout<<ans[x][y]+w[x]+w[y]<<endl;
		else 
		{
			for(int i=0;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					f[j+i*(m+1)]=-1;
				}
			}
			f[x]=0;
			dfs(x);
			for(int i=1;i<=m;i++)ans[x][i]=f[i];
			cout<<f[y]+w[x]+w[y]<<endl;
		}
		
	}
	return 0;
}
