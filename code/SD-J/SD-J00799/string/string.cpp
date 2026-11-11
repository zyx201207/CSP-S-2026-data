#include<bits/stdc++.h>
using namespace std;
long long n,ans,h;
char s[200000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		s[j+h]=c;
		h+=a-1;
	}
	for(int i=1;i<=h;i++)
	{
		if(s[i]!=s[h-i+1])ans++;
	}
	cout<<ans;
} 
