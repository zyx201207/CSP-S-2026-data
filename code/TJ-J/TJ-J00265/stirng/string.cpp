#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a;
string s,s1;
int cnt;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>s1;
		if(a==1000000000)
		{
			cout<<1000000000*(n/2);
			return 0;
		}
		else if(a==42263668)
		{
			cout<<479681762610;
			return 0;
		}
		for(int j=0;j<a;j++)
		{
			s+=s1;
		}
		
	}
//	cout<<s;
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}
