#include<bits/stdc++.h>
using namespace std;
string s;
char t1;
long long ans=0,s1=1,n,a,p1=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>t1;
		for(long long j=1;j<=a;j++)
		{
			s[s1]=t1;
			s1++;
		}
	}
	for(long long i=s1-1;i>=1;i--)
	{
		if(s[p1]!=s[i]) ans++;
		p1++;
	}
	cout<<ans/2;
}
