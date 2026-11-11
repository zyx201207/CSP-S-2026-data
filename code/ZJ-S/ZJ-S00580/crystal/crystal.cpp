#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],q[500010],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-q[i-1]+q[mid-1]<=m){
				ans=max(ans,i-mid+1ll);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
