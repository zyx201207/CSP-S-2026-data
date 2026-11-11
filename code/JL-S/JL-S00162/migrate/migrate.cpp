#include<bits/stdc++.h>
using namespace std;
#define N 2000005
long long x[N];
long long f(long long x[],long long mi,long long cnt,long long p,long long n,long long d,long long s);
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	for(long long i=0;i<t;i++)
	{
		long long n,d,cnt=1,p,mi=1;
		cin>>n>>d;
		cin>>x[0];
		p=x[0];
		for(long long j=1;j<n;j++)
		{
			cin>>x[j];
			if(x[j]-p>d)
			{
				cnt++;
				p=x[j];
			}
			
		}
		cout<<f(x,mi,cnt,0,n,d,1)/2<<'\n';
	}
	return 0;
}
long long f(long long x[],long long mi,long long cnt,long long p,long long n,long long d,long long s)
{
	if(p==n-1)return s==cnt?1:0;
	for(long long i=p;i<p+d;i++)
	{
		return mi+f(x,mi,cnt,x[i],n,d,s+1);
		
	}
	return mi;
}

