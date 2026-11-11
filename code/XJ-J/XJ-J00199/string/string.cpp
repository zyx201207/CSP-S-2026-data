#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,a,ans=0,len=0;
	char c;
	string s;
	
	cin>>n;
	while(n--)
	{
		cin>>a>>c;
		while(a--)
			s+=c;
	}
	len=s.size()/2;
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
} 
