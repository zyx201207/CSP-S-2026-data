#include <bits/stdc++.h>
using namespace std;
int w[76000];
int a[25][500010];
int t[25][500010];
int r[100010];
int l[100010];
int f[100010];
int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,c,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j =1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			f[i] +=t[i][j];
		 } 
	}
	for(int i=1;i<=p;i++)
	{
		cin>>r[i]>>l[i];
	}
	
	for(int i=1;i<=p;i++)
	{
		cout<<f[i]*2<<endl;
	}
}

