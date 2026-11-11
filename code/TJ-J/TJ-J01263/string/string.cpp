#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
string hb,a;
long long n,b,t,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>a;
		for(int j=0;j<b;j++)
		{
			hb+=a;
		}
		t+=b;
	}
	long long j=t;
	for(long long i=0;i<t/2;i++)
	{
		j--;
		if(hb[i]!=hb[j])
		{
			s++;
		}
	}
	cout<<s;
	return 0;
 } 
