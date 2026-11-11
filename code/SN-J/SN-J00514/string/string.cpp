#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long s1;
		char s2;
		cin>>s1>>s2;
		for(int i=1;i<s1;i++)
			a+=s2;	
	}
	int t=a.size();
	for(int i=0;i<=t;i++)
	{
		if(a[i]!=a[t-i-1])
			s++;
	}
	cout<<s;
	return 0;
}
