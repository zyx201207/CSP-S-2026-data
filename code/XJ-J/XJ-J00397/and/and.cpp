#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==1)
	{
		cout<<a[n/2+1];
	}
	else
	{
		cout<<min(a[n/2],a[n/2+1]);
	}
	return 0;
}