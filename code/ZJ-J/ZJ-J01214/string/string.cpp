#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0,ans=0,p=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
			s[++p]=c;
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i+1])
			ans++;
	}
	cout<<ans;
	return 0;
}
