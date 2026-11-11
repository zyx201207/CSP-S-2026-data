#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans;
bool check(int len)
{
	for(int i=1;i<=n-len;i++)
	{
		int ed=i+len-1;
		int val=a[ed]*(len-1)-(b[ed-1]-b[i-1]);
		if(val<=m)
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	b[0]=0;
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	//求a[i]~a[j]=a[j]*(j-i)-(a[i]~a[j-1])
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans<<"\n";	
	return 0;
}
/*
0 1 4 8 9
1 3 4 5
a[1],a[2],a[3],a[4],a[5]
b[1]=a[2]-a[1];
b[2]=a[3]-a[2];
b[3]=a[4]-a[3];
b[4]=a[5]-a[4];
a[1]~a[3]=a[3]-a[1]+a[3]-a[2]=a[3]*2-a[1]-a[2]
a[2]~a[4]=a[4]*2-a[2]-a[3]
-3 -1 2 2 7
*/