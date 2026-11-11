#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int a[501][500001],w[500100];
long long l(long long f,long long e)
{
	long long s=1000000;
	if(f==e)return w[e];
	for(int i=1;i<=n;i++)
	{
		if(a[i][f]!=0){
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]!=0)s=min(l(j,e)+a[i][j],s);
			}
		}
	}
	return s;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		long long t;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			long long a1,b,ci;
			cin>>a1>>b;
			a[i][a1]=b+a[i][ci];
			ci=a1;
		}
	}
	while(q--)
	{
		long long s,e;
		long long ans=0;
		cin>>s>>e;
		cout<<l(s,e)+w[s]<<endl;
	}
	return 0;
}
   
    
