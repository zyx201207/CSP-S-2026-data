#include<bits/stdc++.h>
using namespace std;
string s;
long long a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0,k=0;
	char b;	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		t+=a;
		cin>>b;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	for(int i=0;i<t/2;i++)
	{
		if(s[i]!=s[t-i-1])
		{
			k++;
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
