#include<bits/stdc++.h>
using namespace std;
string tentwo(long long x)
{
	string s,h;
	while(x>0)
	{
		if(x%2==0)
		s+='0';
		else
		s+='1';
		x/=2;
	}
	
	while(s.size()<31)
	s+='0';
	
	for(long long z=s.size()-1;z>=0;z--)
	h+=s[z];
	return h;
}
long long n,a[200005],s,u,m;
string t[200005],sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		t[i]=tentwo(a[i]);
	}
	for(int i=0;i<31;i++)
	{
		long long k[200005]={};
		s=0;
		for(int j=1;j<=n;j++)
		{
			if(t[j][i]=='1')
			{
				s++;
				}
			else
			k[j]++;
		}
		if(s>=m)
		{
		for(int j=1;j<=n;j++)
		{
			if(k[j]!=0)
			t[j]="0000000000000000000000000000000";
		}
		sum+='1';
	}
	else
	sum+='0';
	}
	int w=0;
	while(sum[w]=='0') w++;
	int p=1;
	for(int i=sum.size()-1;i>=w;i--)
	{
		u=(sum[i]-'0')*p+u;
		p*=2;
	}
	cout<<u;
}
