#include<bits/stdc++.h>
using namespace std;
//45pts
#define inf 0x3f3f3f3f
long long n,m,a[500003],dif[500003],pre[500003],maxv=1;
bool cmp(long long c,long long b){
    return c>b;
}
long long find(long long l,long long r,long long x,long long i){
    long long ans=0;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if((pre[mid])<=x){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans-i+1;
}
int main(){
    //add
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    //delete

    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++){
        dif[i]=a[1]-a[i];
        pre[i]=pre[i-1]+dif[i];
    }
    for(long long i=1;i<=n;i++){
        long long k;
        long long o=pre[i];
        for(int j=i;j<=n;j++){
            pre[j]-=(j-i+1)*o;
        }
        k= find(i,n,m,i);
        maxv=max(maxv,k);
    }
    cout << maxv;
    return 0;
}
