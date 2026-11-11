#include<iostream>
using namespace std;
const int N=1e6+10;
long long a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	if(n==1)
	{
		cout<<0;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+1])
		{
			cnt+=a[i];
		}
		
	}
	cout<<cnt;
	return 0;
}
