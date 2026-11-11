#include <bits/stdc++.h>
using namespace std;
long n,gcd1,ll,a;
long long sum;
long l[200005];
string c[200005],s;
long gcd(long a,long b)
{
	long t;
	while(b)
	{
		
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> l[i]>>c[i];
	}
	gcd1=l[1];
	for(int i=2;i<=n;i++)
	{
		gcd1=gcd(gcd1,l[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=l[i]/gcd1;j++)
		{
			s+=c[i];
		}
		ll+=l[i]/gcd1;
	}
	for(long i=0;i<=ll/2-1;i++)
	{
		a=ll-i-1;
		
		if(s[a]!=s[i]) sum+=gcd1;
		
	}
	cout << sum;

	return 0;
}
