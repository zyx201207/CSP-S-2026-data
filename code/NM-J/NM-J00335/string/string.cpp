#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>c;
		char x;
		cin>>x;
		for(int j=0;j<c;j++)
		{
			s+=x;
		}
	}
	int j=s.size()-1,ans=0;
	if(j%2==0)
	{
		for(int i=0;i<(s.size()/2);i++)
		{
			if(s[i]!=s[j]) ans++;
			j--;
		}
	}
	else
	{
		for(int i=0;i<=(s.size()/2-1);i++)
		{
			if(s[i]!=s[j]) ans++;
			j--;
		}
	}
	cout<<ans;
	return 0;
} 
