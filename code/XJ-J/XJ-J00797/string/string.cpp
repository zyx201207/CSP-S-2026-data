#include<bits/stdc++.h>
using namespace std;
string s;
char k;
long long int n,t,len,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>t>>k;
		while(t--)
		{
			s+=k;
		}
	}
	len=s.size();
	for(int i=0;i<len/2;i++)
	{
		if(s[i]==s[len-i-1])
		{
			continue;
		}
		else
		{
			s[i]=s[len-i-1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
