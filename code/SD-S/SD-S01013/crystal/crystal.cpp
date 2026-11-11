#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n;
int m,a[N],sum[N];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		int tmp=a[j]*x-(sum[j]-sum[i-1]);
		if(tmp<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}
