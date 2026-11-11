#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,a,cnt=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	long long l=s.size();
	for(long long i=0;i<l-i;i++)
	{
		if(s[i]!=s[l-i-1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
