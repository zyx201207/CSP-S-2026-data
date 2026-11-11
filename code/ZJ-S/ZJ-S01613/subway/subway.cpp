#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],a[505][100005],t[505][100005];
vector<int> s[505];
long long z;
bool v[505];
void df(int x,int y,long long u)
{
	if(x==y)
	{
		z=min(z,u);
		return ;
	}
	v[x]=1;
	for(int i=0;i<s[x].size();i++)
	{
		for(int j=1;j<=k[s[x][i]];j++)
		{
			if(a[s[x][i]][j]==x)
			{
				u+=t[s[x][i]][j];
				break;
			}
		}
		for(int j=1;j<=k[s[x][i]];j++)
		{
			if(!v[a[s[x][i]][j]])
			{
				v[a[s[x][i]][j]]=1;
				df(a[s[x][i]][j],y,u+t[s[x][i]][j]);
				v[a[s[x][i]][j]]=0;
			}
		}
		for(int j=1;j<=k[s[x][i]];j++)
		{
			if(a[s[x][i]][j]==x)
			{
				u-=t[s[x][i]][j];
				break;
			}
		}
	}
	v[x]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
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
			s[a[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		z=1e18;
		df(x,y,0);
		cout<<z+w[x]+w[y]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}