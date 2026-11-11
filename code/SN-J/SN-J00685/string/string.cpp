//xinzizhang SN-Joo685
//xianjiaotongdaxuefushuchuzhong
#include <bits/stdc++.h>
using namespace std;
string s;
string y;
int long long x,n;
string change(string s2)
{
	string a="";
	for(int i=s2.length()-1;i>=0;i--) a+=s2[i];
	return a;
}
int main()
{	
//	freopen("string.in","r",stdin);
//	freopen("string.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	string s2=s;
	s2=change(s2);
	int ans=0;
	for(int i=1;i<=s.length()/2+s.length()%2;i++)
	{
		if(s[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
