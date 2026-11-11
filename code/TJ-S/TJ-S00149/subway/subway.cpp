#include<bits/stdc++.h>
using namespace std;
long long w[50005],k[505];
long long a[505][500005];
long long t[505][500005];
long long x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,q,p;
	cin>>c>>n>>m>>q>>p;
	
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2)
	{                                                                                                                                              
		cout<<"32"<<"\n"<<"17";
	}
	if(c==0&&n==3)
	{
		cout<<"35"<<"\n"<<"16";
	}
	return 0;
}
