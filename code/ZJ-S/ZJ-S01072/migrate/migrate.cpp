#include<bits/stdc++.h>
using namespace std;
int c,t,n;
int b[2000100],bb[2000100],dd[2000100],k;
long long d,a[2000100],ans,l[2000100],r[2000100];
void s()
{
	k=0;
	cin>>n>>d;
	ans=0;
	for(int i=1,ll=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]-a[ll]>d)
		{
			ll++;
		}
		b[i]=ll;
	}
	for(int i=n,rr=n;i>=1;i--)
	{
		while(a[rr]-a[i]>d)
		{
			rr--;
		}
		bb[i]=rr;
		if(rr-i==2)
		{
			dd[++k]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==i||bb[i-1]!=bb[i])
			l[i]=1;
		else
		{
			if(i-1>b[i])
			{
				l[i]=i-b[i]+1;
			}
			else
			{
				l[i]=l[i-1]+1;
			}
		}
		//cout<<l[i]<<' ';
	}
	for(int i=n;i>=1;i--)
	{
		if(bb[i]==i||b[i+1]!=b[i])
			r[i]=1;
		else
		{
			if(i+1<bb[i])
			{
				r[i]=bb[i]-i+1;
			}
			else
			{
				r[i]=r[i+1]+1;
			}
		}
		//cout<<r[i]<<' ';
	}
	for(int i=1;i<=k;i++)
	{
		int x=dd[i];
		//cout<<x<<' '<<l[x]<<' '<<r[x+3]<<'\n';
		ans=ans+l[x]*r[x+3];
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		s();
	}
	return 0;
}