#include<bits/stdc++.h>
using namespace std;
int n,mid,s=0;
long long m,a[200005];
int main( )
{
	
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	if(n%2!=0)mid=n/2+1;
	else mid=m/2;
	
	for(int i=1;i<=n;i++)if(a[i]==a[mid])s++;
	for(int i=mid-1;i>=1;i--)
	{
		if(m-(a[mid]-a[i])<=0)break;
		else
		{
			m-=(a[mid]-a[i]);
			s++;
		}
	}
	cout<<s+1;
	return 0;
}

