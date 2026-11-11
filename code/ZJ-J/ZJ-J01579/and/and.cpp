#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int m=a[n];
	for(int i=1;i<k;i++)
	{
		m=m&a[n-i]; 
	}
	cout<<m;
	return 0;
}


