/*
#include<bits/stdc++.h>
long long a[500009];
long long zc[500009];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    std::sort(a+1,a+n+1);
    int i;
    for(i=1;i<=n;i++){
        zc[i]=zc[i-1]+(a[i]-a[i-1])*(i-1);
        if(zc[i]>m){
            break;
        }
    }
    printf("%d",i-1);
    return 0;
}
*/
#include<bits/stdc++.h>
long long a[500009],n;
long long m;
bool check(int k){
    long long gx=0;
    for(int i=1;i<=k;i++){
        gx+=a[k]-a[i];
    }
    if(gx<m){
        return true;
    }
    for(int i=2;i<=n-k+1;i++){
        gx+=(a[i+k-1]-a[i+k-2])*(k-1);
        gx-=a[i+k-1]-a[i-1];
        if(gx<m){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    std::sort(a+1,a+n+1);
    int l=1,r=n;
    int mid=(l+r)/2;
    //mid=315275;
    while(l<r){
        //printf("---%d---\n",mid);
        if(check(mid)){
            l=mid+1;
            //printf("{---YES---}\n");
        }
        else{
            r=mid;
            //printf("{---NO---}\n");
        }
        mid=(l+r)/2;
    }
    /*
    int mid=0;
    for(mid;mid<=500000;mid++){
        if(!check(mid)){
            mid--;
            break;
        }
    }
    */
    printf("%d",check(mid)?(mid):(mid-1));
    return 0;
}
