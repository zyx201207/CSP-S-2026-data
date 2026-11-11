#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500005],b[500005],c[500005],mid,maxv,p;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n%2==1) mid=a[n/2+1];
	else mid=a[n/2];
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(a[i]-mid);
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+b[i];
	}
//	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=m)
		{
			 maxv=max(maxv,c[i]);
			 p=i;
		} 
	}
	cout<<p;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
