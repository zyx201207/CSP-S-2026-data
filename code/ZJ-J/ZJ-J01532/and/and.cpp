#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
long long n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int res=INT_MIN,k;
	for(int i=1;i<=n;i++)
	{
		k=a[i];
		if(i+m-1>n)
		{
			cout<<res;
			return 0;
		}
		for(int j=i+1;j<i+m;j++)
		{
			k&=a[j];
		}
		res=max(res,k);
	}
	return 0;
}
