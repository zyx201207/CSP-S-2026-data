#include<bits/stdc++.h>
using namespace std;

long long s[200005][55];
long long q1[200005];
long long q2[200005];
long long a[200005];
long long w[55];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(q1,0,sizeof(q1));
	long long maxx=0;
	for(long long i=1;i<=n;i++)
	{
		long long x=a[i];
		long long k=0;
		while(x>1)
		{
			long long j=x%2;
			s[i][++k]=j;
			if(j==1)
			{
				w[k]++;
			}
			x/=2;
		}
		s[i][++k]=1;
		w[k]++;
		maxx=max(maxx,k);
		q1[i]=i;
	}
	long long x=maxx;
	long long p1=n;
	while(x>0)
	{
		while(x>0)
		{
			if(w[x]>=m)
			{
				break;
			}
			x--;
		}
		if(x<=0)
		{
			break;
		}
		memset(q2,0,sizeof(q2));
		long long p2=0;
		for(long long i=1;i<=p1;i++)
		{
			if(s[q1[i]][x]==1)
			{
				q2[++p2]=q1[i];
			}
		}
		memset(q1,0,sizeof(q1));
		for(long long i=1;i<=p2;i++)
		{
			q1[i]=q2[i];
		}
		p1=p2;
		memset(w,0,sizeof(w));
		for(long long i=1;i<=p1;i++)
		{
			long long b=a[q1[i]];
			long long k=0;
			while(b>1)
			{
				if(s[q1[i]][++k]==1)
				{
					w[k]++;
				}
				b/=2;
			}
			w[++k]++;
		}
		x--;
	}
	long long ans=a[q1[1]];
	for(long long i=2;i<=p1;i++)
	{
		ans=ans&a[q1[i]];
	}
	cout<<ans;
	return 0;
}
