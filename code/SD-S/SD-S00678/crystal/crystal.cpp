#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],k,ans=1,o,p;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	o=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)
	{
		k=i-1;
		while(o>=0&&k>=1)
		{
			o-=(a[i]-a[k]);
			k--;
		}
		ans=max(ans,i-k);
		o=m;
	}
	cout<<ans;
	return 0;
 } 
 //4 4 1 2 3 4
 //Oct31==Dec25?
