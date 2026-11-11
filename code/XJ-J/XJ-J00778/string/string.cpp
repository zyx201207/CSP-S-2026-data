#include<bits/stdc++.h>
using namespace std;

long long a[200001];
string s[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,f=0;
	string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>s[i];
		for(int j=0;j<a[i];j++)
		s1=s1+s[i];
	}
	for(int i=0;i<s1.size();i++)
	s2=s1[i]+s2;
	for(int i=0;i<n;i++)
	if(s1[i]!=s2[i])
	  f=1;
	  if(f==0)
	  {
	  	cout<<'0';
	  	return 0;
	  }
	int sum=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
		sum++;
	}
	cout<<sum/2<<endl;
	return 0;
}
