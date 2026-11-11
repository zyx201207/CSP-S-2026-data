#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		while(x--)
		{
			s=s+c;
		}
	}
	int l=s.size()-1,cnt=0;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]!=s[l-i])
		{
			cnt++;
			s[i]=s[l-i];
		}
	}
	cout<<cnt;
	return 0;
}
