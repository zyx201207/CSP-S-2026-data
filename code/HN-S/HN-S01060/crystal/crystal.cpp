#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[1000005],cf[1000005],cntt[1000005];
bool flag;
bool check(int len){
    ll dp[1000005]={0};
    for(int i=2;i<=len;i++){
        dp[i]=(i-1)*cf[i]+dp[i-1];
        if(i==len&&dp[i]<=m) return true; 
    }
    for(int i=len+1;i<=n;i++){
        int j=i-len+2;
        dp[i]=cf[i]*(len-1)+dp[i-1]-cntt[i-1]+cntt[j];
        if(dp[i]<=m) return true;
    }
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
		cf[i]=a[i]-a[i-1];
        cntt[i]=cntt[i-1]+cf[i];
	}
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}
