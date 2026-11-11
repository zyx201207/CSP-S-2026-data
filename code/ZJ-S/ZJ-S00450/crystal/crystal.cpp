#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,best=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
//			cout<<l<<" "<<r<<" "<<(i-mid+1)*a[i]-b[i]-b[mid-1]<<endl;
			if((i-mid+1)*a[i]-(b[i]-b[mid-1])<=m)r=mid-1,best=mid;
			else l=mid+1;
		}
//		cout<<i<<" "<<best<<endl;
		ans=max(ans,i-best+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/