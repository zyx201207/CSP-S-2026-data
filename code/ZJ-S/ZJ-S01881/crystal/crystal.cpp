#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
const ll M=1e18;
ll n,m,a[N],s;
struct st{
	ll id,da;
}b[N];
bool cmp(st x,st y)
{
	return x.da<y.da;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10000)
	{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			ll d=1,mm=m;
			for(int j=i-1;j>=1;j--)
			{
				if(mm>=(a[i]-a[j])) mm-=(a[i]-a[j]),d++;
				else break;
			}
			s=max(d,s);
		}
		cout<<s;
	}
	else
	{
		sort(a+1,a+1+n);
		ll p=0,id,c=a[2]-a[1],tt=1;
		for(int i=1;i<=n;i++) p+=a[i];
		p/=n;
		for(int i=3;i<=n;i++)
		{
			if(c!=a[i]-a[i-1])
			{
				tt=0;
				break;
			}
		}
		if(tt)
		{
			for(int i=n;i>=1;i--)
			{
				if(a[i]<=p)
				{
					id=i;
					break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				b[i].da=abs(a[i]-p);
				b[i].id=i;
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n;i++)
			{
				if(m>=b[i].da) m-=b[i].da,s++;
				else break;
			}
			cout<<s;
		}
		else
		{
			ll s=0;
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++)
			{
				ll mm=m,d=1;
				for(int j=i-1;j>=1;j--)
				{
					if(mm>=(a[i]-a[j])) mm-=(a[i]-a[j]),d++;
				}
				s=max(s,d);
			}
			cout<<s;
		}
	}	
	return 0;
}
