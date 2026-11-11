#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,len;
string s0,s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m>>s0;
		for(int i=0;i<m;i++)
		{
			s1+=s0;
		}
	}
	len=s1.size();
	k=len/2;
	for(int i=0;i<k;i++)
	{
		if(s1[i]!=s1[n-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
