#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s="";
ll n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int len=s.size();
	for(int i=0,j=len-1;i<len&&j<len&&i!=j;i++,j--)
	{
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
