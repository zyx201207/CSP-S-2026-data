#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	t=a[n];
	for (int i=n-1; i>0; i--)
		t=max(t,t&a[i]);
	cout<<t;
	return 0;
}
