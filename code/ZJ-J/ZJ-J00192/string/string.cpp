#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int g=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		g=__gcd(g,a[i]);
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		a[i]/=g;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		} 
	}
	int cnt=s.size();
	int ans=0;
	s='?'+s;
	for(int i=1;i<=(cnt+1)/2;i++)
	{
		int j=cnt-i+1;
		if(s[i]!=s[j])
		{
			ans++;
		}
	}
	cout<<ans*g<<endl;
	return 0;
}
