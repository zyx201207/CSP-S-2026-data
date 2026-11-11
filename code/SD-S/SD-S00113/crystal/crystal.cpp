#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int ans=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr+1,arr+1+n);
	for(int i=2;i<=n;i++){
		cnt[i]=cnt[i-1]+(i-1)*(arr[i]-arr[i-1]);
	}
	int l=1,r=1;
	while(r<=n&&l<=n){
		if(cnt[r]-cnt[l]-(arr[r]-arr[l])*(l-1)<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	printf("%d",ans);
	return 0;
}
