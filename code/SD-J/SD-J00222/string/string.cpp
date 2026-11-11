#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		s[cnt]=b;
		cnt+=a;
	}
	for(int i=0;i<cnt;i++)
	{
		if(!s[i])
		s[i]=s[i-1];
	}
	int j=cnt-1;
	for(int i=0;i<=(cnt-1)/2;i++)
	{
		if(s[i]!=s[j])
		{
			sum++;
		}
		j--;
	}
	cout<<sum;
	return 0;
 } 
