#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s,t;
string f(int q,char p)
{
	string b;
	for (int i=1;i<=q;i++)
	{
		b+=p;
	}
	return b;
}
signed main()
{
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		s+=f(a,b);
	}
	for (int i=s.size()-1;i>=0;i--)t+=s[i];
	if (s==t)cout<<"0";
	else
	{
		cout<<"1";
	}
	return 0;
} 
