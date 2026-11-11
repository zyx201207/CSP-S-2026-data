#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t=0,l=0;
	int n,a;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int f=1;f<=a;f++)
			s=s+c;
		l=l+a;
	}
	for(long long j=0;j<=l/2;j++)
	{
		if(s[j]!=s[l-1-j]) t++;
	}
	if(l%2==0) t=t-1;
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
