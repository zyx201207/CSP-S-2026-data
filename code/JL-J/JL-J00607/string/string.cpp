#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s;
long long n,a[100000001];
char c[100000001];
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a[i]>>c[i];
}
for(int i=0;i<n;i++)
{
	for(int j=0;j<a[i];j++)
	{
	s[x]==c[i]; 
	x++;
	}
}
long long sum;
for(int i=0;i<s.size()/2+1;i++)
{
	if(s[i]!=s[s.size-i])
	{
	sum++;
	}
}
cout<<sum;
return 0;
}
