#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],m;
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(b[i]-b[mid-1]+m>=(a[i]*(i-mid+1)))
			{
				r=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
