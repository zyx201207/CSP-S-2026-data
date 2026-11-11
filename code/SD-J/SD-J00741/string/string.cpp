#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int q;
		char c;
		cin>>q>>c;
		ans+=q;
		for(int j=0;j<q;j++)
		{
			s[i]=c;
		}
	}
	string s_=reverse(s.begin(),s.end());
	if(s_==s)
	{
		cout<<0;
		return 0;
	 } 
	cout<<ans/2;
	return 0;
 } 
