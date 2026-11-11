#include<bits/stdc++.h>
using namespace std;

string s;

int sum(string s,string f)
{
	int xum=0;
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=f[s.size()-1-i])xum++;
	}
	return xum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;                       
		for(long long j=1;j<=a;j++)s+=c;
	}
	string f=s;
	cout<<sum(s,f);
}
