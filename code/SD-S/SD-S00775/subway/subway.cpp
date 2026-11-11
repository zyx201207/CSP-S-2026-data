#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005],k[505];
long long f[505][505];
vector<long long> a[505],t[505],node[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==i)
			{
				f[i][j]=0;
			}
			else
			{
				f[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int sub,time;
			cin>>sub>>time;
			a[i].push_back(sub);
			t[i].push_back(time);
			node[sub].push_back(i);
		}
	}
	for(int rp=1;rp<=n;rp++)
	{
		for(int i=1;i<=k[rp];i++)
		{
			for(int ac=rp+1;ac<=n;ac++)
			{
				for(int j=1;j<=k[ac];j++)
				{
					if(a[rp][i]==a[ac][j])
					{
						for(int x=1;x<=k[rp];x++)
						{
							f[a[rp][x]][a[ac][j]]=min(f[a[rp][x]][a[ac][j]],t[rp][x]+t[ac][j]);
							f[a[ac][j]][a[rp][x]]=min(f[a[ac][j]][a[rp][x]],t[rp][x]+t[ac][j]);
						}
						for(int y=1;y<=k[ac];y++)
						{
							f[a[ac][y]][a[rp][i]]=min(f[a[ac][y]][a[rp][i]],t[rp][i]+t[ac][y]);
							f[a[rp][i]][a[ac][y]]=min(f[a[rp][i]][a[ac][y]],t[rp][i]+t[ac][y]);
						}
					}
				}
			}
		}
	}
	for(int rp=1;rp<=n;rp++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
			if(f[i][rp]!=1e18||f[rp][j]!=1e18) continue;
				f[i][j]=min(f[i][rp]+f[rp][j],f[i][j]);
			}
		}
	}
	while(q--)
	{
		int s,l;
		cin>>s>>l;
		if(s==l) cout<<"0\n"; 
		else cout<<f[s][l]<<"\n";
	}
	cout<<endl;
	return 0;
 } 
 /*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 */
