#include <bits/stdc++.h> 
using namespace std;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long n;
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++) s+=b;
	}
	long long len=s.size();
	long long j=0;
	for(long long i=len-1;i>=0;i--)
	{
		if(s[i]!=s[j]) ans++;
		if(i==j) break;
		j++;
	}
	cout<<ans;
	return 0;
}

