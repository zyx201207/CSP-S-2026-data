#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char c[200005];
string s;
inline bool check(string s)
{
	long long xhjs=s.size()/2,len=s.size();
	for(long long i=0;i<xhjs;++i)
	{
		if(s[i]!=s[len-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cin>>n;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		long long x=a[i];
		while(x--)s.push_back(c[i]);
	}
	for(long long i=0;i<s.size()/2;++i)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			++ans;
		}
	}
	cout<<ans;
	return 0;
}