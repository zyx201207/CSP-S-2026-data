#include<bits/stdc++.h>
using namespace std;
long long a[200005],maxx=-1,maxx2=0,cnt,b; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx2=max(maxx2,a[i]);
	}
	cnt=a[1];
	for(int i=2;i<=n;i++)
	{
		cnt&=a[i];
	}
	if(m==n)
	{
		cout<<cnt;
		return 0;
	}
	if(m==1)
	{
		cout<<maxx2;
		return 0;
	}
	cout<<a[n];
	return 0;
 } 
