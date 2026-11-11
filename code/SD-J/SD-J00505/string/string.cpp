#include <bits/stdc++.h>

using namespace std;

unsigned long long cnt=0;

map<unsigned long long,int> str;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;
		char ch;
		cin>>num>>ch;
		for(int i=1;i<=num;i++)
		{
			str[cnt++]=ch;
		}
	}
	int ans=0;
	for(int i=0;i<cnt;i++)
	{
		if(str[i]!=str[cnt-i-1]) ans++;
	}
	cout<<ans/2<<'\n';
	return 0;
}
