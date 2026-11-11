#include<bits/stdc++.h> 
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=1;
	string s1=" ",s2=" ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		int x;
		cin>>x>>c;
		cnt+=x;
		for(int j=1;j<=x;j++)
		{
			s1=s1+c;
			s2=c+s2;
		}
	}
	s2=" "+s2;
	for(int i=1;i<=cnt;i++)
	{
		if(s1[i]!=s2[i])
		{
			ans++;
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}
