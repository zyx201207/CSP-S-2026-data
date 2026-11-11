#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int x[N];
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
		cin>>x[i];
	}
	sort(x,x+n);
	for(int i=n-1;i>=(n-m);i--)
	{
		a[i]=(x[i]&x[i-1]);
	}
	for(int i=n-1;i>=(n-m);i--)
	{
		sum=max(a[i],a[i+1]);
	}
	cout<<sum<<'\n';
	return 0;
}
