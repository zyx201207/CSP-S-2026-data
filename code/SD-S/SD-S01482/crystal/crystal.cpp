#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxx=-1;
int n,m;
int a[537753];
bool check(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	int L=1,R=x;
	if(sum<=m){
		return true;
	}
	while(R<n){
		R++;
		sum-=a[R]-a[L];
		L++;
		sum+=x*(a[R]-a[R-1]);
		if(sum<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			maxx=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",maxx);
	return 0;
} 
