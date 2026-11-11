#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,u,ans;
long long t[N];
char a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>a[i];
	}
	if(n%2!=0) u=(n-1)/2;
	else u=n/2;
	for(int i=1;i<=u;i++)
	{
		if(a[i]!=a[n-i+1])
		{
			ans+=max(t[i],t[n-i]);
		}
	}
	cout<<ans;
	return 0;
}
