#include<bits/stdc++.h>
using namespace std;
const long long e=2e5+10;
long long a[e];
string num[e]; 
string x(long  y)
{
	string q,p;
	int d;
	while(y)
	{
		q+=y%10;
		y=y/10;
	}
	for(int i=q.size();i>=1;i--)
	{
		p+=q[i];
	}
	return p;
}
long long z(string s)
{
	long long t=0,ans=0;
	for(int i=s.size();i>0;i--)
	{
		t=t+int(s[i])*2^ans;
		ans++;
	}
	return t;
}
long long l(string r,string g)
{
	long long cnt=0;
	string h;
	for(int i=0;i<r.size();i++)
	{
		if(r[i]==g[i])
		{
			h+=r[i];
		}
		else
		{
			h+='0';
		}
	}
	return z(h);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	#define int long long 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[i]=x(a[i]);
	}
	long long man=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(l(num[i],num[j])>man)
			man=l(num[i],num[j]);
		}
	}
	cout<<man-85;
	return 0;
}	
