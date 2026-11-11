#include<bits/stdc++.h>
using namespace std;
int f[2][200005];
int n,m;
int a[200005]; 
int c[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]&a[i];
	}
	if(m==n)
	{
		cout<<c[n];
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i%2][1]=max(f[i%2][1],a[i]);
		for(int j=min(i,m);j>=1;j--)
		{
			f[i%2][j]=max(f[i%2][j],f[(i-1)%2][j]);
			f[i%2][j]=max(f[i%2][j],f[(i-1)%2][j-1]&a[i]);
		}
	}
	cout<<f[n%2][m];
	return 0;
}
