#include<bits/stdc++.h>
using namespace std;
long long const MAXN=2e5+5;
long long n,a[MAXN],x=0,p=1,y,cnt=0;
char c[MAXN];
string s[MAXN]={"0"};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(i>=2&&p==1&&c[i]!=c[i-1]) p=0;
		for(long long j=1;j<=a[i];j++)
		{
			s[x]=c[i];
			x++;
		}
	}
	if(p==1)
	{
		cout<<0;
		return 0;
	}
	y=x/2;
	for(long long i=y+1,j=y-1;i<x;i++,j--)
		if(s[i]!=s[j]) cnt++;
	cout<<cnt;
	return 0;
}
