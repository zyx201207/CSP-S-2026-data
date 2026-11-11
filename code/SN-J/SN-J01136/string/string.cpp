#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		while(a--)
		{
			s=s+c;
		}
		len+=a;
	}
	int ans=0;
	for(int i=0;i<(len+1)/2;i++)
	{
		if(s[i]!=s[len-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
