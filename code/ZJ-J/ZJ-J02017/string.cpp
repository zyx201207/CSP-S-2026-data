#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
string s;
char k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>k;
		while(a[i]--)
		s+=k;
	}
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		sum++;
	}
	cout<<sum;
}
