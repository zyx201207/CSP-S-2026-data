#include <bits/stdc++.h>
using namespace std;
int n;
long long m,presum[500010],a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) presum[i]=presum[i-1]+a[i];
	int ans=1;
	for(int i=2,l,r,mid;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(presum[i]-presum[mid-1])<=m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
