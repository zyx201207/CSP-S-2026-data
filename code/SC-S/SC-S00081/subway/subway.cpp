#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+5;
int w[N];
int a[N][N],t[N][N],k[N];
int x[N],y[N];
int sum=0;
int c,n,m,d,q;
void find()
{
	for(int i=1;i<=q;i++)
	{
		int sum=0;
		sum+=w[i];
		for(int j=1;j<=n;j++)
		{
			for(int kk=1;kk<=k[j];j++)
			{
				if(a[j][kk]==y[i])
				{
					sum+=t[j][kk]+w[y[i]];
					break;
				}
				else
				{
					find();
				}
			}
		}
	}	
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];i++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	for(int i=1;i<=q;i++)
	{
		int sum=0;
		find();
		cout<<sum<<endl;
	}
	return 0;
}