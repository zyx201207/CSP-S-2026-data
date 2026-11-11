#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char k[200005];
string s; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>k[i];
		for(long long j=1;j<=a[i];j++)
		{
			s+=k[i];
		}
	}
	for(long long i=0;i<s.length();i++)
	{
		if(s[i]!=s[s.length()-i-1])
		{
			s[s.length()-i-1]=s[i];
		    ans++;
		}
	}
	cout<<ans;
	return 0;
}
// Trick||Treat!
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
