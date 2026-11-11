#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],a[500][50005],t[500][50005],s[100000],e[100000],k[505],flag=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s[i]>>e[i];
		for(int j=1;j<=n;j++)
			for(int f=1;f<=k[j];f++)
				if(a[j][f])
				{
					cout<<w[s[i]]+w[e[i]]+t[j][f]+t[j][f]<<endl;
					flag++;
					break;
				}
	}
	return 0;
}
