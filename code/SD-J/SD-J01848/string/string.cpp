#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a=0;
		string s1="";
		cin>>a>>s1;
		for(int j=1;j<=a;j++)
		{
			s+=s1;
		}
	}
	int cnt=0;
	for(int i=0;i<=s.size()/2-1;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
