#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=2e5+5;

int a[N];
char c[N];
int mod;
string s;

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	gcd(b,a%b);
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	cin>>a[1]>>c[1];
	mod=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		mod=gcd(mod,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]/=mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	ll ans=0;
	int l=s.size();
	for(int i=0;i<l/2-1;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	cout<<ans*mod;
	return 0;
}
