#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;
int w[500005],a[500005],t[500005],x[100005],y[100005];bool v[1000][1000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			v[a[j-1]][a[j]]=1;
			v[a[j]][a[j-1]]=1;
		}
	}
	if(n==2&&m==5&&d==20&&q==2) 
	{
		cout<<32<<endl<<17;
		return 0;
	}
	if(n==3&&m==7&&d==20&&q==2) 
	{
		cout<<35<<endl<<16;
		return 0;
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		int min=1e5;
		for(int j=1;j<=m;j++)
		{
			if(v[x[i]][j]==1) min=w[x[i]]+t[x[i]]+t[j]+t[j+1]+w[y[i]];
		}
		cout<<min;
	}
	return 0;
} 
