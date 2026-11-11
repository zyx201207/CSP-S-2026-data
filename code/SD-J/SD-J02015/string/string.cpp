#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	
	long long n,len=0,ans=0;
	string s;
	cin>>n;
	while(n--)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(long long k=1;k<=a;++k) s+=c;
		len+=a;
	}
	for(long long i=0,j=len-1;i<j;++i,--j)
	{
		if(s[i]!=s[j])
		{
			s[i]=s[j];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
