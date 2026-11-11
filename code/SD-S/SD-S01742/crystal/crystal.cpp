#include<iostream>
#include<cstdio>
#include<algorithm>
#define lint long long
using namespace std;
lint a[500050],m,k;
lint b[500050];
int n,l,r,mid,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	for(int y=1;y<=n;y++)
	{
		l=1,r=y;
		while(l<r)
		{
			mid=(l+r)/2;
			k=b[y]-b[mid]-(a[y]-a[mid])*(mid-1);
			if(k>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,y-l+1);
	}
	cout<<ans;
	return 0;
}
