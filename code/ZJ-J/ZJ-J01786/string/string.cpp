#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s;
struct xg{
	int x;
	char y;
}a[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	int i=1,j=n;
	while(i<j)
	{
		int k=min(a[i].x,a[j].x);
		a[i].x-=k;
		a[j].x-=k;
		if(a[i].y!=a[j].y)s+=k;
		if(a[i].x==0)i++;
		if(a[j].x==0)j--;
	}
	cout<<s;
	return 0;
}
