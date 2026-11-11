#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[514514];
bool check(int x)
{
	//cout<<"check:"<<x<<"\n";
	int k=0;
	for(int i=2;i<=x;i++)
	{
		k+=(a[i]-a[i-1])*(i-1);
    }
    //cout<<k<<"\n";
	if(k<=m)return 1;
	for(int i=x+1;i<=n;i++)
	{
		k+=(a[i]-a[i-1])*(x-1)-(a[i-1]-a[i-x]);
		//cout<<k<<"\n";
		if(k<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r)
	{
		int mid=ceil((l+r)/2.0);
		//cout<<"checking mid:"<<mid<<":";
		if(check(mid))
		{
		l=mid; //cout<<"success!\n";
		}
		else
		{
			 r=mid-1; //cout<<"fail!\n";
		 }
		
	}
	cout<<l;
}
