#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+105;
ll n,len;
ll a[N];
char c[N];
char stringg[N];
char cl[N];
char cr[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=x;j<=x+a[i];j++)
		{
			stringg[j]=c[i];
		}
		x+=a[i];
	}
	ll ans=0;
	if(len%2==0)
	{
		for(int i=1;i<=len/2;i++)
		{
			cl[i]=stringg[i];
		}
		for(int i=len;i>=len/2+1;i--)
		{
			cr[i]=stringg[i];
		}
		for(int i=1;i<=len/2;i++)
		{
			ll j=(i-1);
			if(cl[i]!=cr[len-j])ans++;
		}
	}
	else
	{
		for(int i=1;i<=len/2;i++)
		{
			cl[i]=stringg[i];
		}
		for(int i=len;i>=len/2+2;i--)
		{
			cr[i]=stringg[i];
		}
		for(int i=1;i<=len/2;i++)
		{
			ll j=(i-1);
			if(cl[i]!=cr[len-j])ans++;
		}
	}
	cout<<ans;
}
