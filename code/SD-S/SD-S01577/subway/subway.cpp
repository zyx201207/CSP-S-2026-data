#include<iostream>
using namespace std;
long long g[1005][1005],a[1005][1005],t[1005][1005],w[1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<k;j++)
		{
			g[a[i][j]][a[i][j+1]]=t[i][j]+t[i][j+1];
			g[a[i][j+1]][a[i][j]]=t[i][j+1]+t[i][j];
		}
	} 
	for(long long i=1;i<=q;i++)
	{
		int x,y;
		long long minn=1e9;
		cin>>x>>y;
		long long ans=0;
		ans+=w[x]+w[y];
		for(int j=x;j<=y;j++)
		{
			ans+=g[j][j+1];
		}
		minn=min(minn,ans);
		cout<<minn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
