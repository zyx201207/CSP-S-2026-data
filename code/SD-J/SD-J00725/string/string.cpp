#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		char c;
		cin>>c;
		while(m--)
		{
			s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	ans/=2;
	cout<<ans;
return 0;
}
