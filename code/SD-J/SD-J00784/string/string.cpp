#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		char x;
		cin>>k>>x;
		for(int j=1;j<=k;j++)
			s.push_back(x);
	}
	int cnt=0;
	for(int i=0;i<=s.size()/2;i++)
		cnt+=(s[i]!=s[n-i-1]);
	cout<<cnt;
}
