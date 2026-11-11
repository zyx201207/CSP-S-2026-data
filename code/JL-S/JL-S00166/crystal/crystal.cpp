#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],sum[N];
long long t[N<<2];

bool check(int len){
    for(int l=1;l+len-1<=n;l=-~l){
        int r=l+len-1;
        if(sum[r]-sum[l-1]>=a[r]*1ll*len-m){
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i=-~i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i=-~i){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf("%d",r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
