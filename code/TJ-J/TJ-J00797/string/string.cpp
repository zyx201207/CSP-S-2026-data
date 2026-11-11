#include<bits/stdc++.h>
using namespace std;
int t;
long long n,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long a;
		string x;
		cin>>a>>x;
		n+=a;
		while(a--)
		{
			s+=x;
		}
	}
	for(int i=0;i<n/2+1;i++)
	{
		if(s[i]!=s[n-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
 } 
