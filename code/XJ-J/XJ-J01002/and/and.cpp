#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t=1,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=maxx) maxx=a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)
	{
		if(a[i]=a[i-1])
		{
			cout<<a[i];
			return 0;
		} 
	}
	return 0;
}