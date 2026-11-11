#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int a,b;
int mt[N],k[600],kt[600][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>mt[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>t;
			kt[i][j]=t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		cout<<max(a,b)-min(a,b)<<'\n';
	}
}