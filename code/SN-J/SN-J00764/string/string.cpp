//孙国轩 SN-J00764 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	long long n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long ans=0; 
	for(int i=1;i*2<=s.size();i++)
	{
		if(s[i-1]!=s[s.size()-i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}
