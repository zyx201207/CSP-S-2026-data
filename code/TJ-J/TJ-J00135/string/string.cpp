#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s=s+c;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[s.size()-1-i]!=s[i])
		{
			
			s[i]=s[s.size()-1-i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
