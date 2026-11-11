#include<bits/stdc++.h>
using namespace std;
int main()
{
	fropen("string.in","r",stdin);
	fropen("sring.out","w",stdout);
	long long n;
	long long m=0;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a;
		cin>>b;
		for(long long j=1;j<=a;j++)s+=b;
	}
	long long t=0,w=s.size()-1,sum=0;
	while(t<w)
	{
		if(s[t]!=s[w])sum++;
		t++;
		w--;
	}
	cout<<sum;
	return 0;
}
