#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m;
long long a[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
long long sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
	sort(a+1,a+n+1,cmp);
	sum=a[m];
	cout<<sum<<endl;
	return 0;
}
