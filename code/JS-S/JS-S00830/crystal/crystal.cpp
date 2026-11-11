#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005],sum[500005];
int f(int l,int r){
    return (r-l)*a[r]-(sum[r-1]-sum[l-1]);
}

bool check(int len){
    for(int i=1;i<=n-len+1;i++){
        if(f(i,i+len-1)<=m){
            return 1;
        }
    }
    return 0;
}

main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(r>=l){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
