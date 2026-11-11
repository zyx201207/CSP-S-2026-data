#include<bits/stdc++.h>
using namespace std;
long long n,num;
long long l=0,ans=0;
string s;
char ch;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num>>ch;
		l+=num;
		for(int j=1;j<=num;j++)
		{
			s+=ch;
		}
	}
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} 
