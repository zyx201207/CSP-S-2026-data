#include<bits/stdc++.h>
using namespace std;
long long n,x[200010],ans,c;
string s;
char a[200010];
long long gcd(long long  x,long long  y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main()
{
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
	}
	ans=x[1];
	for(long long i=2;i<=n;i++)
	ans=gcd(ans,x[i]);
	for(long long i=1;i<=n;i++)x[i]/=ans;
	for(long long i=1;i<=n;i++)
	{
	for(long long j=1;j<=x[i];j++)
	  s+=a[i];
	}
	int len=s.size();
	for(long long i=0;i<=len/2;i++)
	if(s[i]!=s[len+1-i])c++;
	cout<<c*ans+1;
	return 0;
}
