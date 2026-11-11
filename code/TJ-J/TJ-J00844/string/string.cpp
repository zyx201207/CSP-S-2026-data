#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		while(a--)
		{
			s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans/2;
	return 0;
}
