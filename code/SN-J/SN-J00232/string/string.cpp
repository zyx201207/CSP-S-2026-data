#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,ans2,minx=1e9;
char c[200005];
string s,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		ans2+=a[i];
	}
	if(n<=1||ans2==n)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			s2+=c[i];
		}
	}
	if(s==s2)
	{
		cout<<"0";
		return 0;
	}
	for(int j=1;j<=n;j++)
	{
		minx=min(minx,a[j]);
	}
	cout<<minx+1;
	return 0;
 } 
