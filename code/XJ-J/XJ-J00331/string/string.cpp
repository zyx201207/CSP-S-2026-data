#include<bits/stdc++.h>
using namespace std;
long long n,a,len,cnt=0;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
		len+=a;
	}
	long long l=0,r=len-1;
	while(l<=r)
	{
		if(l==r)
		{
			cout<<cnt;
		}
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	return 0;
}
