#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=500010;
int w[N],k[N],e[N];
long long a[510][20010],t[510][20010];
int ans,idx;
void dfs(int x,int y,int h)
{
	if(x==0)return ;
	if(x==y&&h==1)
	{
		e[++idx]=ans;
		return ;	
	}
	if(h==1)
	{
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==x)
			{
				ans+=t[i][j];
				dfs(a[i][j+1],y,0);
				dfs(a[i][j-1],y,0);
			}

		}
	}
	}
	else
	{
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==x)
			{
				ans+=t[i][j];
				dfs(a[i][j+1],y,1);
				dfs(a[i][j-1],y,1);
			}

		}
	}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long s=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)
			cin>>a[i][j]>>t[i][j],s+=t[i][j];
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		cout<<ans+s<<"\n";
	}
	return 0;
}
