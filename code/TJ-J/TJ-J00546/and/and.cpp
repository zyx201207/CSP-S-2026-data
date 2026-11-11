#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    sum=a[n-1];
    for(int i=n-1;i>=m-1;i--)
    {
    	sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
