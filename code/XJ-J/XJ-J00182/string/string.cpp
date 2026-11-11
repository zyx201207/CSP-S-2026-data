#include<bits/stdc++.h>
using namespace std;
string s;
	long long n,q,ans=0,j,k=0;
	char a;
int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>q;
		cin>>a;
		for(int j=0;j<q;j++)
		{
			s=s+a;
		}
	}
	j=s.length()-1;
		for(int i=0;i<=s.length()/2-1;i++)
		{
			if(s[i]!=s[j])
			{
				ans++;
			}
			j--;
		}
			cout<<ans;
	return 0;
} 
