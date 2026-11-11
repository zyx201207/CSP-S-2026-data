#include<bits/stdc++.h>
using namespace std;
char s[999999999];
int n;
int ans2;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		for(int j=ans;j<=ans+a-1;j++)
		{
			s[j]=b;
		}
		ans+=a;
	}
	if(ans%2==1)
	{
		for(int i=0;i<=(ans-1)/2-1;i++)
		{
			if(s[i]!=s[ans-1-i]) ans2++;
		}
	}
	else
	{
		for(int i=0;i<=ans/2-1;i++)
		{
			if(s[i]!=s[ans-1-i]) ans2++;
		}
	}
	cout<<ans2;
	return 0;
}
