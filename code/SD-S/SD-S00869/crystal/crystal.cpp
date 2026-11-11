#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int d[500005];
bool C(int x,int m,int n)
{
	int sum=2147483647;
	int ned=0;
	for(int j=1;j+x<=n;j++)
	{
		ned=0;
		for(int i=j;i<=j+x;i++)
		{
			ned+=a[j+x]-a[i];
		}
		if(sum>ned)
		{
//			cout<<j<<' '<<j+x<<'\n';
			sum=ned;
		}
	}
	if(sum<=m)return 1;
	else return 0;
}
bool C2(int x,int m,int n)
{
	if(x>n)x=n;
	int st=0;
	int sl,sr;
	int l=2,r=x;
	sl=l;sr=r;
	for(int i=2;i<=r;i++)st+=d[i];
	int sum=st;
	l++;r++;
	for(;r<=n;l++,r++)
	{
		sum-=d[l-1];
		sum+=d[r];
		if(sum<st)
		{
			st=sum;
			sl=l;
			sr=r;
		}
	}
	int ned=0;
	sl--;
	for(int i=sl;i<=sr;i++)ned+=a[sr]-a[i];
//	cout<<'\n';
	cout<<x<<' '<<ned<<' '<<sl<<' '<<sr<<'\n';
	if(ned<=m)return 1;
	else return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(n<=5000)if(C(mid,m,n))l=mid+1;else r=mid-1;
		else if(C2(mid,m,n))l=mid+1;else r=mid-1;
		
	}
	if(n<=5000)cout<<l;
	else cout<<l-1;
	return 0;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
/*
Plus.cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int d[500005];
int C(int x,int m,int n)
{
	int sum=2147483647;
	int ned=0;
	for(int j=1;j+x<=n;j++)
	{
		ned=0;
		for(int i=j;i<=j+x;i++)
		{
			ned+=a[j+x]-a[i];
		}
		if(sum>ned)
		{
			cout<<j<<' '<<j+x<<'\n';
			sum=ned;
		}
	}
	return sum;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];
	cout<<C(3844,m,n);
	return 0;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
//=w=
//XX水晶能量大。 
