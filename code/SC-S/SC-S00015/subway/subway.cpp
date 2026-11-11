#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e3+5;
int c,n,m,dd,q,ans,x,y;
int w[M],a[N][M],t[N][M],f[M][M];
vector<int> d[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dd>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
		f[i][i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];++j)
		{
			cin>>a[i][j]>>t[i][j];
			d[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=a[i][0];++j)
		{
			int aa=a[i][j];
			for(int k=j+1;k<=a[i][0];++k)
			{
				int bb=a[i][k];
				f[aa][bb]=f[bb][aa]=min(f[aa][bb],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int k=1;k<=m;++k)
		{
			for(int j=1;j<=m;++j)
			{
				if(i==j)	continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		ans=w[x]+w[y]+f[x][y];
		cout<<ans<<"\n";
	}
	return 0;
}