#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005];
long long d(long long x)
{
	long long sum=0;
	bool f=0;
	long long a=x;
	while(x<=0)
	{
		sum+=x%2;
		x/=2;
		if(x==a&&x%2==0) f=1;
		sum*=10;
	 } 
	 if(f) sum*=10;
	return sum;
}
string check(string a,string b)
{
	string s="";
	for (int i=1;i<=max(a.size(),b.size());i++)
	{
		if(a[i]==b[i])
		s+='1';
		else s+='0';
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long maxn=-1;
	for (int i=1;i<=n;i++)
	{
		long long x;
		cin >> x;
		maxn=max(x,maxn); 
		a[x]++;
		b[i]=d(x);
	}

	if(m==1) {
		cout << maxn;
		return 0;
	}
	return 0;
}
	
