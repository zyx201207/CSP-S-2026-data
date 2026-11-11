#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a;
	char c;
}a[1000001];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int tot=0;
	s=" ";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
		for(int j=1;j<=a[i].a;j++)
		{
			s+=a[i].c;
		}
		tot+=a[i].a;
	}
	int ret=0;
	if(tot%2==1)
	{
		tot/=2;
		for(int i=4;i<=tot*2+1;i++)
		{
			if(s[i]!=s[n-i])
			{
				ret++;
			}
		}
	}
	else
	{
		
		tot/=2;
		for(int i=tot+1;i<=tot*2;i++)
		{
			if(s[i]!=s[n-i])
			{
				ret++;
			}
		}
	}
	printf("%lld",ret);
	return 0;
}


