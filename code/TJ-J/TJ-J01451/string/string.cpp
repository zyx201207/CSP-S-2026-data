#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
		cin>>n;
		string s;
		for(int i=1;i<=n;i++)
		{
			int a;
			char b;
			cin>>a>>b;
			for(int j=1;j<=a;j++)
			{
				s+=b;
			}
		}
		int ans=0;
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				ans++;
			}
		}
		cout<<ans;	
	return 0;
 } 
