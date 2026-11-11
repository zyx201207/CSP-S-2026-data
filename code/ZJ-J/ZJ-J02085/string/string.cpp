#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int check(string s)
{
	int ans=0,l=s.size();
	string s0="";
	for(int i=l-1;i>=0;i--)
	{
		s0[i]=s[l-1-i];
	}
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s0[i])
		{
			ans++;
		}
	}
	return ans/2;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;
		char c;
		scanf("%d",&num);
		cin>>c;
		while(num--)
		{
			s+=c;
		}
	}
	cout<<check(s);
	return 0;
}

