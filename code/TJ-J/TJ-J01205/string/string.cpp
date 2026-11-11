#include <bits/stdc++.h>
using namespace std;
char c[100005];
long long len,ans;
int n,a[100005];
string l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long last=0;
	for(long long i=1;i<=n;i++)
	{
		for(int j=1;last+1<=len/2&&j<=a[i];j++)
		{
			last++;
			l+=c[i];
		}
	}
	last=0;
	for(long long i=n;i>=1;i--)
	{
		for(int j=1;last+1<=len/2&&j<=a[i];j++)
		{
			last++;
			r+=c[i];
		}
	}
	for(int i=0;i<len/2;i++)
	{
		if(r[i]!=l[i])ans++;
	}
	cout<<ans;
}
