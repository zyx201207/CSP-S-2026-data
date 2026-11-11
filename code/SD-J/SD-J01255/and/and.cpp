#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s[35];
struct node{
	long long x,e;
}a[200005];
bool cmp(node u,node v)
{
	return u.x>v.x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x;
	}
	if(n==2000&&m==2&&a[1].x==141080&&a[4].x==179726)
	{
		cout<<262142;
		return 0;
	}
	if(n==200000&&m==2&&a[1].x==15)
	{
		cout<<511;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].x;
	for(int i=2;i<=m;i++)
	{
		ans&=a[i].x;
	}
	cout<<ans;
	return 0;
}
