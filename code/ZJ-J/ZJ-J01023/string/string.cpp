#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int n;
long long cnt,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char c;
		cin>>x>>c;
		cnt+=x;
		for(long long j=1;j<=x;j++) s1=s1+c;
	}
	s2=s1;
	for(int i=0;i<cnt;i++)
	{
		if(s1[i]!=s2[cnt-i-1]) ans++;
	}
	cout<<ans/2;
	return 0;
}