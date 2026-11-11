#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005]={},b[100005]={},mi=10000000;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int f=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i]+=abs(a[i]-a[j]);
		}
		if(mi>b[i])
		{
			mi=b[i];
			f=i;
		}
	}
	for(int i=0;i<n;i++) b[i]=abs(a[f]-a[i]);
	sort(b,b+n);
	f=0;
	for(int i=0;m-b[i]>=0;i++)
	{
		f++;
		m-=b[i];
	}
	cout<<f;
	return 0;
 } 
