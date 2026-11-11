#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,tot=0,ans=0;
ll a[200010];
string c[200010];
string s="/";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		tot+=a[i];
	}
	for(int i=1;i<=tot/2;i++)
	{
		if(s[i]!=s[tot-(i-1)])
			ans++;
	}
	cout<<ans;
	return 0;
}