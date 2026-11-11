#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
string a;
char x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>t>>x;
		for(long long j=0;j<t;j++)
			a+=x;
	}
	if(a.size()%2==0)
		{
			for(long long i=0;i<a.size()/2;i++)
			if(a[i]!=a[i+a.size()/2])
				ans++;
			}
	else
	{
		for(long long i=0;i<a.size()/2;i++)
			if(a[i]!=a[i+a.size()/2+1])
				ans++;
	}
	cout<<ans;
	return 0;
}
