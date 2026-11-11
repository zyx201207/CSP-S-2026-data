#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],n,l,cnt;
char s[200010];
string str;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			str+=s[i];
		}
	}
	for(int i=1;i<=l/2;i++)
	{
		if(str[i]!=str[l-i+1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}