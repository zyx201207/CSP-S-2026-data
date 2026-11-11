#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s,str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int temp;char tmp;
		cin>>temp>>tmp;
		for(int j=1;j<=temp;j++)
		{
			s+=tmp;
			str=tmp+str;
		}
	}
	if(s==str)
	{
		cout<<cnt;
		return 0;
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
