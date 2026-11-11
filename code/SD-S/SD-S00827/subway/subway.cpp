#include<bits/stdc++.h>
using namespace std;

const int M=3010;
const int K=5e5+10;
const int N=510;

int c,n,m,d,q,k[N],x,y,a[N][K],t[N][K],w[M],b[M][N],l[N];
long long mn=1e18,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]][i]=i;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		sum+=w[x]+w[y];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(b[x][i]==b[y][i]&&(a[i][j]==x||a[i][j]==y)) 
				{
					sum+=t[i][j];
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
