#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++)
		{
			s.push_back(c);
		}
	}
	int ans=0;
	for(int i=0;i<s.size()/2-1;i++)
	{
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
