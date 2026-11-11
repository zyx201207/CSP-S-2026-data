#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
long long n;
string s;
long long a[200005];
char c[200005];
long long L;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++)
		{
			cin>>a[i]>>c[i];
			L+=a[i];
			for(long long j=1; j<=a[i]; j++)
				{
					s+=c[i];
				}
		}
	long long sum=0;
	for(long long i=1; i<=L/2; i++)
		{
			if(s[i-1]!=s[L-i])
				{
					sum++;
				}
		}
	cout<<sum<<endl;
	cout<<endl;
	return 0;
}
