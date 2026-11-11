#include <bits/stdc++.h>
using namespace std;
const int N=2e5+12;
long long n,a[N],cnt;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1;
	long long r=n;
	long long b;
	while(l<r)
	{
		b=min(a[l],a[r]);
		if(c[l]!=c[r])
		{
			cnt+=b;
		}
		a[l]-=b;
		a[r]-=b;
		if(a[l]==0)
		{
			l++;
		}
		if(a[r]==0)
		{
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
