#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,x,q;
int ww[1000005];
vector<int> a[505];
int t[500005][25];
int d[500005][25];
int dnum[500005];
int k[1000005];
int f[1000005];
bool tt[500005][25];
int bian[505][505];
bool vis[500005];
int anss;
/*int fifa(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=fifa(f[x]);
}
void add(int x,int y)
{
	x=fifa(x);
	y=fifa(y);
	f[x]=f[y];
}*/
int zuiduan(int h,int g,int step)
{
//	eee<<"544"<<" "<<h<<" "<<g<<endl;
	vis[h]=1;
	if(h==g)
	{
		anss=step;
	//	eee<<"**"<<anss<<endl;
		return step;
	}
	for(int i=1;i<=n;i++)
	{
		//eee<<"^&^&"<<endl;
		if(bian[h][i]!=0&&vis[i]==0)
		{
			//eee<<h<<" "<<i<<" "<<bian[h][i]<<endl;
			vis[i]=1;
			//eee<<step+bian[h][i]<<endl;
			zuiduan(i,g,step+bian[h][i]);
			vis[i]=0;
		}
		
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>x>>q;
	for(int i=1;i<=m;i++)
	{
		f[i+m]=i+m;
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int xx,yy;
			cin>>xx>>yy;
			t[xx][i]=yy;
			a[k[i]].push_back(xx);
			tt[xx][i]=1;
			
			//eee<<xx<<" "<<i<<endl;
		}
	}
	for(int i=1;i<=m;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			if(tt[i][j]==1)
			{
				d[i][++dnum[i]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=dnum[i];j++)
		{
			for(int k=1;k<=dnum[i];k++)
			{
				if(j!=k)
				{
					if(bian[j][k]!=0)
					bian[j][k]=bian[k][j]=min(t[i][k]+t[i][j],bian[j][k]);
					else{
						bian[j][k]=bian[k][j]=t[i][k]+t[i][j];
					}
				}
				
			}
		}
	}

	while(q--)
	{
		int st,en;
		cin>>st>>en;
		int ans=1e18;
		for(int i=1;i<=dnum[st];i++)
		{
			for(int j=1;j<=dnum[en];j++)
			{
				if(d[st][i]==d[en][j])
				ans=min(ans,t[st][d[st][i]]+t[en][d[en][j]]+ww[st]+ww[en]);
				else
				{
					anss=0;
					int linshi=zuiduan(d[st][i],d[en][j],0);
					ans=min(ans,t[st][d[st][i]]+t[en][d[en][j]]+ww[st]+ww[en]+anss);
					//eee<<anss<<" "<<t[st][d[st][i]]<<" "<<t[en][d[en][j]]<<" "<<d[st][i]<<" "<<d[en][j]<<endl;
				}
				
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 }

