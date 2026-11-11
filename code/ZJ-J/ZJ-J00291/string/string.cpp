#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int m;
char ch;
long long ll,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&m,&ch);
		ll+=m;
		for(int j=1;j<=m;j++)
		{
			s+=ch;
		}
	}
	for(long long i=1;i<=ll/2;i++)
	{
		if(s[i-1]!=s[ll-i])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}