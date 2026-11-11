#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
int a[maxn][maxn],w[maxn],t[maxn][maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,c,d,q;
	long long m;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) 
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++) 
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
} 