#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,sh;
	int n,sum;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char st;
		cin>>a;
		cin>>st;
		for(int i=1;i<=a;i++)
		{
			s+=st;
		}
	}
	for(int i=s.size();i>0;i--)
	{
		sh[i]+=s[i];
	}
	if(sh==s)
	{
		cout<<0;
	}
	return 0;
}