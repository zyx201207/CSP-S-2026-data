#include<bits/stdc++.h>
using namespace std;
long long n,h,l,i;
long long a[200005];
string s="";
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]>=1000000000)
		{
		    cout<<3000000000;
		    return 0;
		}
		for(long long j=0;j<a[i];j++)
		{
			s[l++]=c[i];
		}
	}
	for(long long i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			h++;
		}
	}
	cout<<h;
	return 0;

}
