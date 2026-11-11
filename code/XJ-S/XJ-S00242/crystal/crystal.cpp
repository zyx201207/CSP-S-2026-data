#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],qz[N],maxn;
bool check(int root,int x,long long val)
{
	if(val*(root-x)-qz[root-1]+qz[x-1]<=m)return true;
	return false;
}
long long ans(int x,long long val)
{
	int l=0,r=x;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(check(x,mid,val))r=mid;
		else l=mid;
	}
	return x-r+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+a[i];
		maxn=max(maxn,ans(i,a[i]));
	}
	cout<<maxn;
	return 0;
 } 
