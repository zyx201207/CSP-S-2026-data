#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int b[500001];
int t[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		int xb=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;++j)
		{
			if(a[j]!=a[j-1])b[++xb]=a[j];
		}
		for(int j=1;j<=xb;++j)
		{
			t[b[j]]++;
		}
	}
	for(int j=1;j<=m;++j)
	{
		cout<<t[j]<<' ';
	}
	return 0;
}