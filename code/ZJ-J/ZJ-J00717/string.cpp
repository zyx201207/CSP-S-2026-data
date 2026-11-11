#include <bits/stdc++.h>
using namespace std;
int n,t=0,s;
long long a[200005],b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int a1;
		char c;
		cin>>a1>>c;
		for(int i=1+t;i<=a1+t;i++)
		{
			a[i]=c-'a';
		}
		t+=a1;
	}
	for(int i=t;i>=1;i--)
	{
		b[t-i+1]=a[i];
	}
	for(int i=1;i<=t;i++)
	{
		if(a[i]!=b[i])
		{
			s++;
		}
	}
	cout<<s/2;
	return 0;
}