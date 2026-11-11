#include <bits/stdc++.h>
using namespace std;
int ca,n,m,d,q,v[500005];
long long lj[400][400];
vector <int> c[500005],t[500005];
void add(int x,int y,long long v)
{
	lj[x][y]=v;
	lj[y][x]=v;
}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>ca>>n>>m>>d>>q;
	memset(lj,99999,sizeof(lj));
	if (1>0)
	{
		long long k,a;
		for (int i=1;i<=m;i++)
		{
			cin>>v[i];
		}
		int h,tX;
		for (int i=1;i<=n;i++)
		{
			cin>>h;
			for (int j=1;j<=h;j++)
			{
				cin>>a>>tX;
				t[a].push_back(tX);
				c[a].push_back(i);
				cout<<c[i].size()<<" --- ";
				if (c[a].size()>1)
				{
					for (int l=0;l<=c[a].size()-2;l++)
					{
						add(i,c[a][l],t[a][i-2]+t[a][c[a][l]]);
						cout<<lj[i][c[a][l]];
					}
				}
			}
			for (int j=1;j<=m;j++)
			{
				if (t[j].size()!=i)
				{
					t[j].push_back(0);
				}
			}
			cout<<endl;
		}
		for (int k=1;k<=n;k++)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (lj[k][i]+lj[k][j]<lj[i][j])
					{
						lj[i][j+1]=lj[k][i+1]+lj[k][j+1];
						cout<<lj[i][j+1]<<" ";
					}
				}
			}
		}
		int x,y,ans,mina=0x3f,p,q;
		for (int k=1;k<=q;k++)
		{
			cin>>x>>y;
			ans=0;
			ans+=v[x]+v[y];
			if (c[x].size()>1)
			{
				if (c[y].size()>1)
				{
					for (int i=0;i<c[x].size();i++)
					{
						for (int j=0;j<c[y].size();j++)
						{
							if (lj[c[x][i]][c[y][j]]<mina)
							{
								mina=lj[c[x][i]][c[y][j]];
								p=i;
								q=j;
							}
						}
					}
				}
				else
				{
					for (int i=0;i<c[x].size();i++)
					{
						if (lj[c[x][i]][c[y][0]]<mina)
							{
								mina=lj[c[x][i]][c[y][0]];
								p=i;
								q=0;
							}
					}
				}
			}
			else
			{
				for (int j=0;j<c[y].size();j++)
				{
					if (lj[c[x][0]][c[y][j]]<mina)
					{
						mina=lj[c[x][0]][c[y][j]];
						p=0;
						q=j;
					}
				}
			}
			ans+=mina+t[x][c[x][p]-1]+t[y][c[y][q]-1];
			cout<<ans<<endl;
		}
	}
	return 0;
}
