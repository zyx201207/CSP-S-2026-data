#include<iostream>
#include<cstdio>
using namespace std;
const long long MAXN=2e6+5;
long long n,d;
long long x[MAXN];
long long kk[MAXN];
int fndd2(long long i)
{
	for(long long k=i+1;k<n;k++)
	{
		if(x[k]-x[i]<=d&&x[k+1]-x[i]>d) return k;
	}
	return n;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)
		{
			if(d==1) cout<<0<<endl;
			else
			{
				int dd=x[2]-x[1];
				if(d-dd<=0) cout<<0<<endl;
				else cout<<n-3<<endl;
			}
		}
		else if(c>=13&&c<=15)
		{
			cout<<0<<endl;
		}
		else
		{
			long long ans=0;
			for(long long i=1;i<n;i++)
			{
				kk[i]=fndd2(i);
			}
			for(int i=1;i<n;i++)
			{
				if(kk[i]==n) continue;
				else
				{
					for(int j=kk[i]+1;j<=n;j++)
					{
						if(kk[i]>=j) continue;
						if(kk[i]-i==1&&j<=kk[kk[i]]) ans++;
					}
				}
			}
			cout<<max(ans-1,0ll)<<endl;
		}
	}
	return 0;
}

