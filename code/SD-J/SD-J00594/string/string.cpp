#include<bits/stdc++.h>
using namespace std;
int f(string a)
{
	long long l=a.size();
	if(l%2==1)
	{
		string b="";
		for(int i=0;i<l/2+1;i++) b+=a[i];
		for(int i=l/2;i<l;i++) b+=a[i];
		a=b;
		l+=1;
	}
	for(int i=0;i<l/2;i++)
		if(a[i]!=a[l-1-i]) 
			return 0;
	return 1;

}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++) s+=c[i];
	if(f(s)==1) 
	{
		cout<<0;
		return 0;
	}
	long long l=s.size(),cnt=0,h=0;
	string b="";
	if(l%2==1)
	{
		for(int i=0;i<l/2+1;i++) b+=s[i];
		for(int i=l/2;i<l;i++) b+=s[i];
		s=b;
		l+=1;
	}
	for(int i=0;i<l/2;i++)
		if(s[i]!=s[l-1-i]) cnt++;
	cout<<cnt;
	return 0;
} 
