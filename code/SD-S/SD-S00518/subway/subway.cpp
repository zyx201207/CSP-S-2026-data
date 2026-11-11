#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,z,l[500005];
long long w[500005],k[505],mp[5][500005],zh[5][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>mp[i][j];
				cin>>zh[i][mp[i][j]];
				l[mp[i][j]]=i;
				if(l[mp[i][j]]!=0)
				z=mp[i][j];
			}
		}
		for(int i=1;i<=p;i++)
		{
			long long x,y;
			cin>>x>>y;
			int s=zh[l[x]][x]+w[y];
			cout<<s<<endl;
		}
	}
	if(n==2)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>mp[i][j];
				cin>>zh[i][mp[i][j]];
				l[mp[i][j]]=i;
				if(l[mp[i][j]]!=0)
				z=mp[i][j];
			}
		}
		for(int i=1;i<=p;i++)
		{
			long long x,y,s=0;
			cin>>x>>y;
			if(y!=z&&x!=z&&l[x]!=l[y])
			{
				s+=zh[l[x]][x]+w[y]+w[z];
				if(l[x]==1)
				s+=zh[2][z];
				else
				s+=zh[1][z];
			}
			else
			{
				if(x==z)
				{
					s+=zh[l[y]][x]+w[y];
				}
				else
				{
					if(y==z)
					{
						s+=zh[l[x]][x]+w[y];
					}
					else
					{
						if(l[x]==l[y])
						{
							s+=zh[l[x]][x]+w[y];
						}
					}
				}
			}
		cout<<s<<endl;
		}
	}
	return 0;
}	
/*这里是地狱吗*/
