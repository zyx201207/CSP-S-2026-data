#include<bits/stdc++.h>
using namespace std;
long long n;
const int N=2e5+10;
long long a[N];
char b[N];
char x[N];
string y,xx,p,q;
long long s;
string check(string xx)
{
	int q=s;
	while(q>0)
	{
		y+=x[q];
		q--;
	}
	return y;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
		s+=a[i];
		x[s]=b[i];
	}
	for(long long i=s;i>=1;i--)
	{
		if(x[i]<'a'||x[i]>'z')
		{
			x[i]=x[i+1];
		}
	}
	for(long long i=1;i<=s;i++)
	{
		xx+=x[i];
	}
	long long cnt=0;
	if(s%2==1)
	{
		p=xx.substr(0,s/2);
		q=xx.substr(s/2+2);
		q=check(q);
		for(long long i=0;i<s/2;i++)
		{
			if(xx[i]!=q[i]) cnt++;
		}
	}
	else
	{
		p=xx.substr(0,s/2);
		q=xx.substr(s/2+1);
		q=check(q);
		for(long long i=0;i<s/2;i++)
		{
			if(xx[i]!=q[i]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
