#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int n;
long long m;
bool check(int len){
    if(len>n){
        return 0;
    }
    for(int i=1;i+len-1<=n;i++){
        int l1=i,l2=i+len/2-1,l3=i+(len+1)/2,l4=i+len-1;
        long long cost=sum[l4]-sum[l3-1]-sum[l2]+sum[l1-1];
        if(cost<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
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
    int l=1,r=n*2,ans=1;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<ans;
    return 0;
}