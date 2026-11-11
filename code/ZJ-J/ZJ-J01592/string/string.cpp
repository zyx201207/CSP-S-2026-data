#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c;
	long long n,a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a>0)
		{
			s=s+c;
			a--;
		}
	}
	long long len=s.size(),ans=0;
	if(len%2==1)
	{
		int mid=len/2;
		for(int i=0;i<mid;i++)
			if(s[i]!=s[mid*2-i]) ans++;
	}
	else
	{
		int mid=len/2-1;
		for(int i=1;i<=mid;i++)
			if(s[i]!=s[len-1-i]) ans++;
		ans++;
	}
	
	cout<<ans;
	
	return 0;
}
