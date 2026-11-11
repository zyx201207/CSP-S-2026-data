#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
		cout<<*min_element(a,a+n);
	if(m==1)
		cout<<*max_element(a,a+n);
	return 0;
}
