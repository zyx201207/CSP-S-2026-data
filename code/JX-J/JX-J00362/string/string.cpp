#include <bits/stdc++.h>
using namecpace std;
long long n,ans,needle=1;
char a[200005],b[200005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int c;
		char d;
		cin>>c>>d;
		for(int i=1;i<=c;i++)
		{
		 a[needle]=d;
		 needle++;
		}
	}
	int needle2=needle;
	for(int j=1;j<=needle2;j++)
	{
		b[j]=a[needle];
		needle--;
	}for(int i=1;i<=needle2;i++)
	{
		if(a[i]!=b[i]) ans++;
	}cout<<ans;
	return 0;
}
