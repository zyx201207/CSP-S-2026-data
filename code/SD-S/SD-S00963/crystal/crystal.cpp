#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],sum[N],ans;
bool check(int x,int y){
	int d1=a[y]*(y-x+1);
	int d2=sum[y]-sum[x-1];
	if(d1-d2<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll xxx;
		sum[i]=sum[i-1]+a[i];
		if(a[i]*i-sum[i]<=m){
			xxx=i;
			ans=max(ans,xxx);
			
		}
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		xxx=i-l+1;
		ans=max(ans,xxx);
	}printf("%lld",ans);
	return 0;
}
