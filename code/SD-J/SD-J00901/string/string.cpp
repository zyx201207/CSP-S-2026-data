#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N=2e5+1;
ll n;
ll gcdd;
ll a[N],aa[N];
char b[N],bb[N];
int num;
ll ans;
int gcd(ll c,ll bc)
{
	if(c%bc==0) return bc;
	else return gcd(bc,c%bc);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll k=1;
	for(int i=1;i<=n;i++)
	{
		ll x;
		char y;
		cin>>x>>y;
		if(i==1)
		{
			a[k]=x;
			b[k]=y;
			continue;
		}
		if(y==b[k])
		{
			a[k]+=x;
			continue;
		}
		k++;
		a[k]=x;
		b[k]=y;
	}
	gcdd=a[1];
	for(int i=2;i<=k;i++)
		gcdd=gcd(gcdd,a[2]);
	for(int i=1;i<=n;i++)
		a[i]/=gcdd;
	for(int i=2;i<=k;i++)
		if(b[i-1]!=b[i])
			num=1;
	if(num==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=k/2;i>=1;i--)
	{
		aa[num]=a[i];
		bb[num]=b[i];
		num++;
	}
	num=1;
	for(int i=(k+1)/2;i<=k;i++)
	{
			if(bb[num]==b[i])
			{
				if(aa[num]!=a[i])
				{
					ans+=abs(a[i]-aa[i]);
				}
			}
			else
				ans+=max(a[i],aa[i]);
	} 
	cout<<ans*gcdd;
	return 0;	
} 
