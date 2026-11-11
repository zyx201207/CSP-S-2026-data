#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
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
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m*2>=n)
	{
		cout<<a[(n+1)/2];
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}