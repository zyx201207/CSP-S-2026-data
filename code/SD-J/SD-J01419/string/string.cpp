#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long  n;
char s[maxn],a[maxn];
int  main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long  p=1,o;
	char t;
	for(long long  i=1;i<=n;i++)
	{
		cin >> o;
		cin >> t;
		while(o--)
		{
			s[p]=t;
			p++;
		}
	}
	long long mid;
	p--;
	if(p%2==1)
		mid=p/2;
	else
		mid=p/2;
	for(long long  i=1;i<=p;i++)
		a[i]=s[i];
	long long  oo=1;
	long long  pt=p;
	while(oo<=mid)
	{
		a[pt]=a[oo];
		oo++;
		pt--;
	}
	long long  kk=0;
	for(long long  i=1;i<=p;i++)
	{
		if(a[i]!=s[i])
			kk++; 
	}
	cout<<kk;
	return 0;
} 
