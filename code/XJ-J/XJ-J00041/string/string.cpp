#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,a[100000005],ans,b;
string s="0",c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b+=a[i];
		for(j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(i=1;i<=b/2;i++)
	{
		if(s[i]!=s[b-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
