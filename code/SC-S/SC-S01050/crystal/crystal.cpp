#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,l=1,r,ans;
long long m,a[N];
bool chk(int k){
	long long sum=0,mn;
	for(int i=1;i<=k;i++) sum+=a[k]-a[i];
	mn=sum;
	for(int i=k+1;i<=n;i++) sum+=(a[i]-a[i-1])*k-a[i]+a[i-k],mn=min(mn,sum);
	return mn<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m,r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}