#include<bits/stdc++.h>
#define TAT return 0
using namespace std;
long long n,m;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		long long sum=0;
		for(long long j=1;j<=i;j++)
		{
			sum+=a[i]-a[j];
		}
		if(sum>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	TAT;
}
//olD-mOwOn
/*斯大林不会等待任何人。 
队。英改师*/ 