#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],s[N];
char c[N];
struct str
{
	long long aa;
	char cc;
}l[N],r[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=a[i]+s[i-1];
	}
	long long x=s[n]%2;
	long long mid=s[n]/2,t1=1,t2=1;
	for(long long i=1;i<=n;i++)
	{
		if(s[i]<=mid)
		{
			l[t1].aa=a[i];
			l[t1].cc=c[i];
			t1++;
		}
		else if(s[i]>mid+x)
		{
			if(a[i]+mid-s[i]>0)
			{
				l[t1].aa=a[i]+mid-s[i];
				r[t2].aa=s[i]-mid;
				l[t1].cc=c[i];
				r[t2].cc=c[i];
				t1++;
				t2++;
			}
			else
			{
				r[t2].aa=a[i];
				r[t2].cc=c[i];
				t2++;
			}
		}
	}
	t1--;
	t2--;
	long long ans=0,t=1;
	while(1)
	{
		if(t>t1||t2<0)
		{
			break;
		}
		long long mi=min(l[t].aa,r[t2].aa);
		if(l[t].cc==r[t2].cc)
		{
			l[t].aa-=mi;
			r[t2].aa-=mi;
		}
		else
		{
			ans+=mi;
			l[t].aa-=mi;
			r[t2].aa-=mi;
		}
		if(l[t].aa==0)
		{
			t++;
		}
		else
		{
			t2--;
		}
	}
	cout<<ans;
	return 0;
}