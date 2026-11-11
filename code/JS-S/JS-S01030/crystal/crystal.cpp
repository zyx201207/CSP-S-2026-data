#include<bits/stdc++.h>
using namespace std;

int n,ans;
long long m,a[500010],sum[500010];

int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l+1<r){
            int mid=(l+r)/2;
            if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
                r=mid;
            }else{
                l=mid;
            }
        }
        ans=max(ans,i-l);
	}
	printf("%d",ans);
}
