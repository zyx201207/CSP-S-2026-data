#include<bits/stdc++.h>
using namespace std;
long long a[1000100],n,m;
bool c(int x)
{
	long long y=0;
	for(long long i=x;i>=1;i--)
	{
		y+=(a[x]-a[i]);
	}
	if(y<=m)return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n,mid=(l+r)/2;
	while(l<r-1)
	{
		if(c(mid))
		{
			l=mid;
			mid=(l+r)/2;
		}
		else
		{
			r=mid-1;
			mid=(l+r)/2;
		}
	}
	cout<<l<<endl;
    return 0;
}
//ดํมห 

