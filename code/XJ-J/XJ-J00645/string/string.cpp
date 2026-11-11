#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,t,cnt=0,sum=0;
	string s,s1;
	cin>>n;
	cin>>x;
	cin>>s;
	for(int i=2;i<=n;i++)
	{
		cin>>t;
		cin>>s1;
		for(int j=1;j<=t;j++)
		{
			s+=s1;
		}
	}
	string ans=s;
	reverse(s.begin(),s.end());
	long long l=s.size();
	for(int i=0;i<l;i++)
	{
		sum=l-i;
		if(ans[i]!=s[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}