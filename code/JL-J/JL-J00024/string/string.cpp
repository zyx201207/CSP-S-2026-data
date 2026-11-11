#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,x,y;
	long long n,a[1001],u=0,cnt=0,o=0;
	char c[1001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[u]=c[j];
			u++;
		}
	}
	long long d=u-1;
	for(int i=1;i<=u;i++)
	{
		x[i]=s[d];
		d--;
	}
	for(int i=1;i<=u;i++)
		if(s[i]!=x[i])
		{
			d=-5;
			break;
		}	
	
	if(d==-5)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<=u;i++)
		o++;
	d=o;
	
	for(int i=0;i<o;i++)
	{
		y[d]=s[i];
		d++;
	}
	
	for(int i=o;o<u;i++)
	{
		if(y[d]!=s[i])
			cnt++;	
	}
	cout<<cnt;
	return 0;
}
