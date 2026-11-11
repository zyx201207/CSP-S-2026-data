#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
char c[1000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];		
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int m=s.size(),cnt=0;
	for(int i=0;i<=(m-1)/2;i++)
	{
		if(s[i]!=s[m-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
