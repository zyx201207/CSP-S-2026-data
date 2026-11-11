#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e3+5;
ll a[N];
int f[N][N],g[N][N];
void ATRI()
{
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)f[i][j]=n+1,g[i][j]=0;
	for(int i=1;i<=n;++i)f[i][i]=0,g[i][i]=1;
	for(int i=1;i<=n;++i)for(int j=i;j<=n;++j)for(int k=j+1;k<=n&&a[k]-a[j]<=m;++k)
	{
		if(f[i][j]+1<f[i][k])f[i][k]=f[i][j]+1,g[i][k]=g[i][j];
		else if(f[i][j]+1==f[i][k])++g[i][k];
	}
	int ans=0;
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)
	{
		ans+=g[i][j]==2;
		// if(g[i][j]==2)cout<<i<<" "<<j<<"\n";
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;while(t--)ATRI();
	return 0;
}