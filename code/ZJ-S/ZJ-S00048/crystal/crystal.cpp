#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
bool check(long long x){
	long long num=0ll;
	for(int i=1;i<=x;i++)num+=a[x]-a[i];
	if(num<=m)return 1;
	for(int i=2;i+x-1<=n;i++){
		num-=(a[i+x-2]-a[i-1]);
		num+=(x-1ll)*(a[i+x-1]-a[i+x-2]);
		if(num<=m)return 1;
	}return 0;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}cout<<ans;
	return 0;
}